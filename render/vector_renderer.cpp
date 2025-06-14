#include "vector_renderer.h"
#include "shader.h"
#include <GL/glew.h>

static ShaderProgram shader;
static GLuint vao, vbo;

void VectorRenderer::init() {
    shader.loadFromFiles("shaders/vector_shader.glsl", "shaders/vector_shader.glsl");
    shader.compile();

    float data[] = {
        -0.5f, -0.5f, 0.2f, 0.1f,
         0.5f, -0.5f, 0.4f, 0.2f,
         0.0f,  0.5f, 0.3f, 0.5f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void VectorRenderer::update(float time) {
    shader.use();
    glUniform1f(glGetUniformLocation(shader.programId, "time"), time);
}

void VectorRenderer::render() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
