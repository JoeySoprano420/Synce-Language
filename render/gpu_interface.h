#pragma once
enum class RendererType {
    OPENGL,
    VULKAN
};

class GPUInterface {
public:
    void initialize(RendererType type);
    void renderFrame();
private:
    RendererType current;
    void renderOpenGL();
    void renderVulkan();
};
