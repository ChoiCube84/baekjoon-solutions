#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> price(N, vector<int>(3, 0));
    vector<vector<int>> dp(N, vector<int>(9, INT_MAX));

    for (int i=0; i<N; i++) {
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }

    // dp[i][0]: Red Start, Red Now
    // dp[i][1]: Red Start, Green Now
    // dp[i][2]: Red Start, Blue Now
    // dp[i][3]: Green Start, Red Now
    // dp[i][4]: Green Start, Green Now
    // dp[i][5]: Green Start, Blue Now
    // dp[i][6]: Blue Start, Red Now
    // dp[i][7]: Blue Start, Green Now
    // dp[i][8]: Blue Start, Blue Now

    dp[0][0] = price[0][0];
    dp[0][4] = price[0][1];
    dp[0][8] = price[0][2];

    for (int i=1; i<N; i++) {
        for (int base=0; base<9; base+=3) {
            int prev0 = min(dp[i-1][base + 1], dp[i-1][base + 2]);
            int prev1 = min(dp[i-1][base + 0], dp[i-1][base + 2]);
            int prev2 = min(dp[i-1][base + 0], dp[i-1][base + 1]);

            dp[i][base + 0] = prev0 == INT_MAX ? INT_MAX : prev0 + price[i][0];
            dp[i][base + 1] = prev1 == INT_MAX ? INT_MAX : prev1 + price[i][1];
            dp[i][base + 2] = prev2 == INT_MAX ? INT_MAX : prev2 + price[i][2];
        }
    }

    int result = min({dp[N-1][1], dp[N-1][2], dp[N-1][3], dp[N-1][5], dp[N-1][6], dp[N-1][7]});

    cout << result;

    return 0;
}
