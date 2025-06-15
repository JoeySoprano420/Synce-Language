#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>

class ScriptInterpreter {
public:
    void loadScript(const std::string& code);
    void execute();

private:
    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> commands;
    std::vector<std::string> lines;

    void registerBuiltinCommands();
};
