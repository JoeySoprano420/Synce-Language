#pragma once
enum WaveType { SINE, SQUARE, NOISE };

struct SoundIRNode {
    WaveType type;
    float frequency;
    float modulation;
};

float generate_wave(const SoundIRNode& node, float time);
void process_audio_frame(float time);
