#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <glm/glm.hpp>
#include "ResourceManager.hpp"
#include "SceneGraph.hpp"
#include "PhysicsEngine.hpp"
#include "ScriptingSystem.hpp"

// Initialize the GLFW window
GLFWwindow* initWindow() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return nullptr;
    }

    return window;
}

// Process user input
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    // Initialize the window
    GLFWwindow* window = initWindow();
    if (!window) return -1;

    // Initialize scripting system
    ScriptingSystem scripting;
    scripting.executeScript("test.lua");

    // Create scene graph
    auto root = std::make_shared<SceneNode>();
    auto child1 = std::make_shared<SceneNode>();
    auto child2 = std::make_shared<SceneNode>();

    root->addChild(child1);
    root->addChild(child2);

    // Create a rigid body for physics
    RigidBody body(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process user input
        processInput(window);

        // Update physics
        body.applyForce(glm::vec3(0.0f, -9.8f, 0.0f));  // Gravity
        body.update(0.016f);  // Assuming 60 FPS

        // Clear the screen to black
        glClear(GL_COLOR_BUFFER_BIT);

        // Traverse scene graph (for this example, no actual rendering)
        root->traverse();

        // Draw a triangle (as a placeholder for the rigid body)
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glEnd();

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up
    glfwTerminate();
    return 0;
}
