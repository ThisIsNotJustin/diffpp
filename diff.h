#ifndef DIFF_H
#define DIFF_H

#include <vector>
#include <iostream>
#include <cassert>
#include <optional>
#include "lcs.h"
#include "myers.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void print_diff(std::vector<std::string> &file_a, std::vector<std::string> &file_b) {
    // normal dp lcs table
    // auto dp = lcs_table(file_a, file_b);

    // table for myers algorithm
    auto dp = myers_table(file_a, file_b);

    // reconstruct path for lcs
    // auto lcs = lcs_elements(dp, file_a, file_b);

    // reconstruct path for myers algorithm
    auto lcs = myers_elements(dp, file_a, file_b);
    int line_a = 0;
    int line_b = 0;

    for (const auto &line : lcs) {
        while (file_a[line_a] != line) {
            std::cout << RED << "- " << file_a[line_a] << RESET << "\n";
            line_a++;
        }

        while (file_b[line_b] != line) {
            std::cout << GREEN << "+ " << file_b[line_b] << RESET << "\n";
            line_b++;
        }

        assert(file_a[line_a] == file_b[line_b]);
        std::cout << " " << file_a[line_a] << "\n";
        line_a++;
        line_b++;
    }

    while (line_a < file_a.size()) {
        std::cout << RED << "- " << file_a[line_a] << RESET << "\n";
        line_a++;
    }

    while (line_b < file_b.size()) {
        std::cout << GREEN << "+ " << file_b[line_b] << RESET << "\n";
        line_b++;
    }
}

// testing output of myers table before trying to reconstruct
void print_myers(std::vector<std::string> &file_a, std::vector<std::string> &file_b) {
    auto dp = myers_table(file_a, file_b);
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            printf("%d\t", dp[i][j]);
            if (i % dp.size() == 0) {
                printf("\n");
            }
        }
    }
}

#endif // DIFF_H