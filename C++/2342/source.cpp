#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int getPower(int start, int end);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> ddr;

    while (true) {
        int temp;
        cin >> temp;

        if (temp == 0) {
            break;
        }
        else {
            ddr.emplace_back(temp);
        }
    }

    if (ddr.empty()) {
        cout << 0;
        return 0;
    }

    vector<vector<vector<int>>> dp(ddr.size(), vector<vector<int>>(5, vector<int>(5, INT_MAX)));

    dp[0][ddr[0]][0] = getPower(0, ddr[0]);
    dp[0][0][ddr[0]] = getPower(0, ddr[0]);

    for (int step=1; step<ddr.size(); step++) {
        for (int right=0; right<5; right++) {
            if (ddr[step] == right) {
                continue;
            }

            for (int prevLeft=0; prevLeft<5; prevLeft++) {
                int prev = dp[step-1][prevLeft][right];
                int curr = prev + getPower(prevLeft, ddr[step]);

                if (prev != INT_MAX && dp[step][ddr[step]][right] > curr) {
                    dp[step][ddr[step]][right] = curr;
                }
            }
        }

        for (int left=0; left<5; left++) {
            if (ddr[step] == left) {
                continue;
            }

            for (int prevRight=0; prevRight<5; prevRight++) {
                int prev = dp[step-1][left][prevRight];
                int curr = prev + getPower(prevRight, ddr[step]);

                if (prev != INT_MAX && dp[step][left][ddr[step]] > curr) {
                    dp[step][left][ddr[step]] = curr;
                }
            }
        }
    }

    int result = INT_MAX;

    for (int left=0; left<5; left++) {
        for (int right=0; right < 5; right++) {
            result = min(result, dp[ddr.size() - 1][left][right]);
        }
    }

    cout << result;

    return 0;
}

int getPower(int start, int end) {
    if (start == end) {
        return 1;
    }
    else if (start == 0) {
        return 2;
    }
    else if (abs(start - end) == 2) {
        return 4;
    }
    else {
        return 3;
    }
}
