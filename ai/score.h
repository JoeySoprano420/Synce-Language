#pragma once
#include <vector>

struct ScoreEvent {
    float inputMagnitude;
    float weight;
    float scaled;
    float finalScore;
};

class ScoreEngine {
public:
    void addEvent(float input, float weight);
    float evaluate();
    void upscaleOutput();
private:
    std::vector<ScoreEvent> events;
    float upscaleFactor = 1.25f;
};
