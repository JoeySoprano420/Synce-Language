#include "render.h"
#include <GL/gl.h> // or <GL/glew.h> for real use

void init_render() {
    // Initialize OpenGL/Vulkan context, shaders, etc.
}

void render_frame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Draw calls, buffer swaps, etc.
}
