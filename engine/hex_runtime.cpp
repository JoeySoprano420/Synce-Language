#include "synth.h"
#include "vector_renderer.h"
#include <chrono>

void runHexIRLive(const std::string& hex) {
    AudioSynth synth;
    synth.loadHexAST(hex);
    synth.generate();

    VectorRenderer vis;
    vis.init();

    float t = 0.0f;
    for (int frame = 0; frame < 60; ++frame) {
        vis.update(t);
        vis.render();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        t += 0.016f;
    }

    synth.play();
}
