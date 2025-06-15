#include "interpreter.h"
#include <sstream>
#include <iostream>

void ScriptInterpreter::loadScript(const std::string& code) {
    std::stringstream ss(code);
    std::string line;
    while (std::getline(ss, line)) lines.push_back(line);
    registerBuiltinCommands();
}

void ScriptInterpreter::execute() {
    for (const auto& line : lines) {
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        std::vector<std::string> args;
        std::string word;
        while (ss >> word) args.push_back(word);

        if (commands.contains(cmd)) {
            commands[cmd](args);
        } else {
            std::cout << "[SCRIPT ERROR] Unknown command: " << cmd << "\\n";
        }
    }
}

void ScriptInterpreter::registerBuiltinCommands() {
    commands["print"] = [](const std::vector<std::string>& args) {
        for (const auto& arg : args) std::cout << arg << " ";
        std::cout << "\\n";
    };
    commands["wait"] = [](const std::vector<std::string>& args) {
        int ms = std::stoi(args[0]);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    };
}
