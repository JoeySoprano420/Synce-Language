#pragma once
#include "fsm.h"
#include <map>

class CampaignAI {
public:
    void setup();
    void update();
    void influence(float chaos, float resolve);

private:
    FSM fsm;
    std::map<std::string, float> weights;
};
