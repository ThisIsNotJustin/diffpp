#ifndef LCS_H
#define LCS_H

#include <vector>
#include <algorithm>

template <typename T>
std::vector<std::vector<int> > lcs_table(std::vector<T> &a, std::vector<T> &b) {
    std::vector<std::vector<int> > dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

int lcs(std::vector<std::vector<int> > &dp, int a_size, int b_size) {
    return dp[a_size][b_size];
}

template <typename T> 
std::vector<T> lcs_elements(std::vector<std::vector<int> > &dp, std::vector<T> &a, std::vector<T> &b) {
    std::vector<T> elements;
    int n = a.size();
    int m = b.size();

    while (n > 0 && m > 0) {
        if (a[n - 1] == b[m - 1]) {
            elements.push_back(a[n - 1]);
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1]) {
            n--;
        }
        else {
            m--;
        }
    }

    std::reverse(elements.begin(), elements.end());
    return elements;
}

#endif // LCS_H
