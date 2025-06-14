#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

class FSM {
public:
    void addState(const std::string& name, std::function<void()> onEnter);
    void addTransition(const std::string& from, const std::string& to, std::function<bool()> condition);
    void update();

private:
    std::string currentState;
    std::unordered_map<std::string, std::function<void()>> states;
    std::vector<std::tuple<std::string, std::string, std::function<bool()>>> transitions;
};
