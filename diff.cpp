#include <fstream>
#include <iostream>
#include <vector>
#include "diff.h"

std::vector<std::string> read_file(std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        file.close();
    } else {
        std::cout << "Error: Unable to open file " << filename << std::endl;
    }

    return lines;
}

int main() {
    std::string a = "tests/testc.c";
    std::string b = "tests/testc2.c";
    // std::string b = "tests/testcpp.cpp";
    std::vector<std::string> file_a = read_file(a);
    std::vector<std::string> file_b = read_file(b);

    print_diff(file_a, file_b);
    // print_myers(file_a, file_b);

    return 0;
}
