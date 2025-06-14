#pragma once
#include <vector>
#include <string>
#include <cstdint>

enum class WaveType {
    SINE, SQUARE, TRIANGLE, SAW, NOISE
};

struct WaveformNode {
    WaveType type;
    float frequency;
    float amplitude;
    float duration;
    uint32_t phase;
};

class AudioSynth {
public:
    void loadHexAST(const std::string& hex);
    void generate();
    void play(); // Placeholder: you could stream this with OpenAL or portaudio

private:
    std::vector<WaveformNode> nodes;
    std::vector<float> output;
};
