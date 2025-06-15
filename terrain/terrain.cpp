#include "terrain.h"
#include <GL/gl.h>
#include <cmath>
#include <cstdlib>

void Terrain::generate(int w, int d) {
    width = w; depth = d;
    heights.resize(width * depth);
    for (int z = 0; z < depth; ++z) {
        for (int x = 0; x < width; ++x) {
            float h = sin(x * 0.1f) * cos(z * 0.1f) * 3.0f;
            heights[z * width + x] = h;
        }
    }
}

void Terrain::render() {
    glBegin(GL_QUADS);
    for (int z = 0; z < depth - 1; ++z) {
        for (int x = 0; x < width - 1; ++x) {
            float h1 = heights[z * width + x];
            float h2 = heights[z * width + (x + 1)];
            float h3 = heights[(z + 1) * width + (x + 1)];
            float h4 = heights[(z + 1) * width + x];

            glVertex3f(x, h1, z);
            glVertex3f(x + 1, h2, z);
            glVertex3f(x + 1, h3, z + 1);
            glVertex3f(x, h4, z + 1);
        }
    }
    glEnd();
}
