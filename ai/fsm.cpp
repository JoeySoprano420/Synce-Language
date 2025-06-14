#include "fsm.h"
#include <iostream>

void FSM::addState(const std::string& name, std::function<void()> onEnter) {
    states[name] = onEnter;
    if (currentState.empty()) {
        currentState = name;
        onEnter();
    }
}

void FSM::addTransition(const std::string& from, const std::string& to, std::function<bool()> condition) {
    transitions.emplace_back(from, to, condition);
}

void FSM::update() {
    for (auto& [from, to, cond] : transitions) {
        if (from == currentState && cond()) {
            std::cout << "FSM: " << from << " → " << to << "\\n";
            currentState = to;
            states[to](); // enter new state
            return;
        }
    }
}
