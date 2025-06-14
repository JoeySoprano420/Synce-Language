#include "gpu_interface.h"
#include <iostream>

// You’ll want to link GLFW, GLAD, and Vulkan SDK
void GPUInterface::initialize(RendererType type) {
    current = type;
    std::cout << "Initializing GPU: ";
    if (type == RendererType::OPENGL) {
        std::cout << "OpenGL Mode\\n";
        // Init GLFW + GLAD
    } else {
        std::cout << "Vulkan Mode\\n";
        // Init Vulkan Instance
    }
}

void GPUInterface::renderFrame() {
    if (current == RendererType::OPENGL) {
        renderOpenGL();
    } else {
        renderVulkan();
    }
}

void GPUInterface::renderOpenGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.6f, -0.4f);
    glColor3f(0.0, 1.0, 0.0); glVertex2f(0.6f, -0.4f);
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.0f, 0.6f);
    glEnd();
}

void GPUInterface::renderVulkan() {
    // Placeholder: Vulkan uses command buffers, pipelines, framebuffers
    std::cout << "[Vulkan] Frame rendered\\n";
}
