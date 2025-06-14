#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aVecMod;

uniform float time;
out vec4 color;

void main() {
    vec2 pos = aPos + sin(time + aVecMod) * 0.1;
    gl_Position = vec4(pos, 0.0, 1.0);
    color = vec4(aVecMod, sin(time), 1.0);
}
