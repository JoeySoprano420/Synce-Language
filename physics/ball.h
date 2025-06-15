#pragma once
class Ball {
public:
    float x, y, vx, vy, radius;
    void update(float dt);
    void checkBounds(float width, float height);
};
