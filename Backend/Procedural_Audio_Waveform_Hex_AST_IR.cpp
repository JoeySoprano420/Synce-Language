// Sound node generation IR
SoundIRNode {
    enum { WAVE_SINE, WAVE_SQUARE, WAVE_NOISE } type;
    float frequency;
    float modulation;
}

// Runtime modulated wave
float generate_wave(SoundIRNode node, float time) {
    switch(node.type) {
        case WAVE_SINE: return sin(time * node.frequency);
        case WAVE_NOISE: return randf(); // procedural
    }
}
