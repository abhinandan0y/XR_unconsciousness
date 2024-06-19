// include/Renderer.hpp
#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void render();

private:
    GLuint shaderProgram;
    // Add more rendering components as needed
};

// src/Renderer.cpp
#include "Renderer.hpp"

Renderer::Renderer() {
    // Initialize rendering components here
}

Renderer::~Renderer() {
    // Cleanup rendering components here
}

void Renderer::render() {
    // Perform rendering here
}
