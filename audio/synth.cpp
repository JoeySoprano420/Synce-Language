#include "synth.h"
#include <cmath>
#include <iostream>
#include <thread>
#include <random>

void AudioSynth::loadHexAST(const std::string& hex) {
    // Simple hex-based mock AST reader
    for (size_t i = 0; i < hex.size(); i += 4) {
        WaveformNode node;
        char h = hex[i];
        node.type = static_cast<WaveType>((h % 5));
        node.frequency = 220.0f + (hex[i + 1] % 100);  // pseudo-freq
        node.amplitude = ((hex[i + 2] % 16) / 15.0f);
        node.duration = ((hex[i + 3] % 10) + 1) * 0.1f;
        node.phase = 0;
        nodes.push_back(node);
    }
}

void AudioSynth::generate() {
    const int sampleRate = 44100;
    for (const auto& node : nodes) {
        int samples = static_cast<int>(node.duration * sampleRate);
        for (int i = 0; i < samples; ++i) {
            float t = i / static_cast<float>(sampleRate);
            float sample = 0.0f;

            switch (node.type) {
                case WaveType::SINE:
                    sample = node.amplitude * std::sin(2.0f * M_PI * node.frequency * t);
                    break;
                case WaveType::SQUARE:
                    sample = node.amplitude * (std::sin(2.0f * M_PI * node.frequency * t) > 0 ? 1.0f : -1.0f);
                    break;
                case WaveType::TRIANGLE:
                    sample = node.amplitude * (2.0f * fabs(2.0f * (t * node.frequency - floor(t * node.frequency + 0.5))) - 1.0f);
                    break;
                case WaveType::SAW:
                    sample = node.amplitude * (2.0f * (t * node.frequency - floor(t * node.frequency + 0.5)));
                    break;
                case WaveType::NOISE:
                    sample = node.amplitude * (((rand() % 2000) / 1000.0f) - 1.0f);
                    break;
            }
            output.push_back(sample);
        }
    }
}

void AudioSynth::play() {
    std::cout << "[Synth Playback Start]\\n";
    for (size_t i = 0; i < output.size(); i += 4410) { // every 0.1s
        std::cout << "Frame[" << i << "] = " << output[i] << "\\n";
    }
    std::cout << "[Synth Playback Done]\\n";
}
