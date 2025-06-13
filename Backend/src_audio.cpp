#include "audio.h"
#include <cmath>
#include <cstdlib>

float generate_wave(const SoundIRNode& node, float time) {
    switch(node.type) {
        case SINE: return std::sin(time * node.frequency);
        case SQUARE: return std::sin(time * node.frequency) > 0 ? 1.0f : -1.0f;
        case NOISE: return (float)std::rand() / RAND_MAX * 2.0f - 1.0f;
        default: return 0.0f;
    }
}

void process_audio_frame(float time) {
    // Example: Output a simple wave
    SoundIRNode node = {SINE, 440.0f, 0.0f};
    float val = generate_wave(node, time);
    // ... output val to buffer
}
