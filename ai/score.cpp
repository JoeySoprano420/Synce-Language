#include "score.h"
#include <cmath>

void ScoreEngine::addEvent(float input, float weight) {
    float scaled = input * weight;
    float score = std::sqrt(scaled) * 10.0f;
    events.push_back({input, weight, scaled, score});
}

float ScoreEngine::evaluate() {
    float sum = 0.0f;
    for (const auto& e : events) sum += e.finalScore;
    return sum / events.size();
}

void ScoreEngine::upscaleOutput() {
    for (auto& e : events) {
        e.finalScore *= upscaleFactor;
    }
}
