#ifndef MYERS_H
#define MYERS_H

#include <vector>
#include <algorithm>

template <typename T>
std::vector<std::vector<int> > myers_table(const std::vector<T> &a, const std::vector<T> &b) {
    int N = a.size();
    int M = b.size();
    int maxD = N + M;
    std::vector<std::vector<int> > dp;
    std::vector<int> V(2 * maxD + 1, 0);
    V[maxD] = -1;
    dp.push_back(V);

    for (int d = 1; d <= maxD; d++) {
        std::vector<int> curr = dp.back();
        for (int k = -d; k <= d; k += 2) {
            int x = 0;

            if (k == -d || (k != d && dp.back()[maxD + k - 1] < dp.back()[maxD + k + 1])) {
                x = dp.back()[maxD + k + 1];
            } else {
                x = dp.back()[maxD + k - 1] + 1;
            }

            int y = x - k;   
            while (x < N && y < M && a[x] == b[y]) {
                x++;
                y++;
            }

            curr[maxD + k] = x;
            if (x >= N && y >= M) {
                dp.push_back(curr);
                return dp;
            }
        }

        dp.push_back(curr);
    }

    return dp;
}

template <typename T>
std::vector<T> myers_elements(const std::vector<std::vector<int>> &trace, const std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size();
    int m = b.size();
    int offset = n + m;
    std::vector<T> result;
    for (int d = trace.size() - 1; d > 0; d--) {
        const auto &V = trace[d];
        int k = n - m;
        int prev_k;
        if (k == -d || (k != d && trace[d - 1][offset + k - 1] < trace[d - 1][offset + k + 1])) {
            prev_k = k + 1;
        } else {
            prev_k = k - 1;
        }
        int prev_x = trace[d - 1][offset + prev_k];
        int prev_y = prev_x - prev_k;
        while (n > prev_x && m > prev_y) {
            result.push_back(a[n - 1]);
            n--;
            m--;
        }

        n = prev_x;
        m = prev_y;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

#endif // MYERS_H
