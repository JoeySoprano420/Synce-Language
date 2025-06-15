#pragma once
class Terrain {
public:
    void generate(int width, int depth);
    void render();

private:
    int width, depth;
    std::vector<float> heights;
};
