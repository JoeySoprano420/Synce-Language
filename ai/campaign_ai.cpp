#include "campaign_ai.h"
#include <iostream>

void CampaignAI::setup() {
    fsm.addState("CALM", [](){ std::cout << "AI: Calm\\n"; });
    fsm.addState("ALERT", [](){ std::cout << "AI: Alert\\n"; });
    fsm.addState("ESCALATED", [](){ std::cout << "AI: Escalated\\n"; });

    fsm.addTransition("CALM", "ALERT", [this]() { return weights["chaos"] > 0.4f; });
    fsm.addTransition("ALERT", "ESCALATED", [this]() { return weights["chaos"] > 0.7f; });
    fsm.addTransition("ESCALATED", "CALM", [this]() { return weights["resolve"] > 0.8f; });
}

void CampaignAI::influence(float chaos, float resolve) {
    weights["chaos"] = chaos;
    weights["resolve"] = resolve;
}

void CampaignAI::update() {
    fsm.update();
}
