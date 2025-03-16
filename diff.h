#ifndef DIFF_H
#define DIFF_H

#include <vector>
#include <iostream>
#include <cassert>
#include <optional>
#include "lcs.h"

void print_diff(std::vector<std::string> &file_a, std::vector<std::string> &file_b) {
    auto dp = lcs_table(file_a, file_b);
    auto lcs = lcs_elements(dp, file_a, file_b);
    int line_a = 0;
    int line_b = 0;

    for (const auto &line : lcs) {
        while (file_a[line_a] != line) {
            std::cout << "- " << file_a[line_a] << "\n";
            line_a++;
        }

        while (file_b[line_b] != line) {
            std::cout << "+ " << file_b[line_b] << "\n";
            line_b++;
        }

        assert(file_a[line_a] == file_b[line_b]);
        std::cout << " " << file_a[line_a] << "\n";
        line_a++;
        line_b++;
    }

    while (line_a < file_a.size()) {
        std::cout << "- " << file_a[line_a] << "\n";
        line_a++;
    }

    while (line_b < file_b.size()) {
        std::cout << "+ " << file_b[line_b] << "\n";
        line_b++;
    }
}

#endif // DIFF_H