#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "Camera.hpp"
#include "FrustumCulling.hpp"
#include "LOD.hpp"
#include "ThreadPool.hpp"
#include "Model.hpp"
#include "stb_image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Example usage of Shader
    Shader shader("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
    shader.use();

    // Example usage of Frustum Culling
    FrustumCulling frustum;
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f/3.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0));
    frustum.updateFrustum(projection, view);

    glm::vec3 point(0, 0, 0);
    if (frustum.isInFrustum(point, 1.0f)) {
        std::cout << "Point is in the frustum.\n";
    } else {
        std::cout << "Point is not in the frustum.\n";
    }

    // Example usage of LOD
    LODModel lodModel;
    lodModel.addModel(10.0f, { /* Low detail vertices */ });
    lodModel.addModel(50.0f, { /* Medium detail vertices */ });
    lodModel.addModel(100.0f, { /* High detail vertices */ });

    float distance = 25.0f;
    const std::vector<float>& model = lodModel.getLODModel(distance);

    // Example usage of ThreadPool
    ThreadPool pool(4);
    pool.enqueue([] { std::cout << "Task 1 executed.\n"; });
    pool.enqueue([] { std::cout << "Task 2 executed.\n"; });
    pool.enqueue([] { std::cout << "Task 3 executed.\n"; });

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Rendering commands here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Process all input
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// GLFW: Whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
