#include "ball.h"
#include <cmath>

void Ball::update(float dt) {
    vy -= 9.8f * dt; // gravity
    x += vx * dt;
    y += vy * dt;
}

void Ball::checkBounds(float width, float height) {
    if (y < radius) {
        y = radius;
        vy *= -0.8f;
    }
    if (x < radius || x > width - radius) {
        vx *= -0.8f;
    }
}
