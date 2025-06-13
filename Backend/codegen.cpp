#include "codegen.h"
#include <sstream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> split_lines(const std::string& input) {
    std::vector<std::string> lines;
    std::istringstream stream(input);
    std::string line;
    while (std::getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::string generate_nasm(const std::string& ir) {
    std::ostringstream out;
    out << "section .data\n";
    out << "msg db 'Compiled Synce Program', 0xA, 0\n";
    out << "section .text\n";
    out << "global _start\n";
    out << "_start:\n";

    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    ; declare " << var << "\n";
            out << "    mov eax, 0\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    mov eax, " << val << "\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    ; use identifier " << id << "\n";
        }
    }

    out << "    mov ebx, 0\n";
    out << "    mov eax, 1\n";
    out << "    int 0x80\n";

    return out.str();
}

std::string generate_cpp(const std::string& ir) {
    std::ostringstream out;
    out << "#include <iostream>\n";
    out << "int main() {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    int " << var << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    int value = " << val << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    std::cout << \"" << id << "\" << std::endl;\n";
        }
    }
    out << "    return 0;\n";
    out << "}\n";
    return out.str();
}

std::string generate_python(const std::string& ir) {
    std::ostringstream out;
    out << "def main():\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    " << var << " = None\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    value = " << val << "\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    print('" << id << "')\n";
        }
    }
    out << "if __name__ == '__main__':\n";
    out << "    main()\n";
    return out.str();
}

std::string generate_go(const std::string& ir) {
    std::ostringstream out;
    out << "package main\n";
    out << "import \"fmt\"\n";
    out << "func main() {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    var " << var << " int\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    value := " << val << "\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    fmt.Println(\"" << id << "\")\n";
        }
    }
    out << "}\n";
    return out.str();
}

std::string generate_rust(const std::string& ir) {
    std::ostringstream out;
    out << "fn main() {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    let mut " << var << ": i32;\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    let value = " << val << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    println!(\"{}\", \"" << id << "\");\n";
        }
    }
    out << "}\n";
    return out.str();
}

std::string generate_javascript(const std::string& ir) {
    std::ostringstream out;
    out << "function main() {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    let " << var << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    let value = " << val << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    console.log('" << id << "');\n";
        }
    }
    out << "}\n";
    out << "main();\n";
    return out.str();
}

std::string generate_java(const std::string& ir) {
    std::ostringstream out;
    out << "public class Main {\n";
    out << "    public static void main(String[] args) {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "        int " << var << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "        int value = " << val << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "        System.out.println(\"" << id << "\");\n";
        }
    }
    out << "    }\n";
    out << "}\n";
    return out.str();
}

std::string generate_c(const std::string& ir) {
    std::ostringstream out;
    out << "#include <stdio.h>\n";
    out << "int main() {\n";
    auto lines = split_lines(ir);
    for (const auto& line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, std::regex("0[0-9]+ DECL (\\w+)"))) {
            std::string var = match[1];
            out << "    int " << var << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ LIT (\\d+)"))) {
            std::string val = match[1];
            out << "    int value = " << val << ";\n";
        } else if (std::regex_match(line, match, std::regex("0[0-9]+ ID (\\w+)"))) {
            std::string id = match[1];
            out << "    printf(\"%s\\n\", \"" << id << "\");\n";
        }
    }
    out << "    return 0;\n";
    out << "}\n";
    return out.str();
}

