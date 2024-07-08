#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

void simulate(void);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        simulate();
    }

    return 0;
}

void simulate(void) {
    const int NONE_OCCUPIED = 0;
    const int UP_OCCUPIED = 1;
    const int DOWN_OCCUPIED = 2;
    const int BOTH_OCCUPIED = 3;
    
    int N, W, result = INT_MAX;
    cin >> N >> W;

    vector<pll> enemy;
    enemy.resize(N);

    for (int i=0; i<N; i++) {
        cin >> enemy[i].first;
    }
    for (int i=0; i<N; i++) {
        cin >> enemy[i].second;
    }

    // First index: Connectedness of Start and End
    // Second index: Connectivity of current index
    // Third index: Current index considering the circle as a line

    vector<vector<vector<int>>> dp(4, vector<vector<int>>(4, vector<int>(N+1, INT_MAX)));

    dp[NONE_OCCUPIED][NONE_OCCUPIED][0] = 2;
    dp[NONE_OCCUPIED][UP_OCCUPIED][0] = 2;
    dp[NONE_OCCUPIED][DOWN_OCCUPIED][0] = 2;
    dp[NONE_OCCUPIED][BOTH_OCCUPIED][0] = 1 + (enemy[0].first + enemy[0].second > W);

    dp[UP_OCCUPIED][NONE_OCCUPIED][0] = 3;
    dp[UP_OCCUPIED][UP_OCCUPIED][0] = 2;
    dp[UP_OCCUPIED][DOWN_OCCUPIED][0] = 2;
    dp[UP_OCCUPIED][BOTH_OCCUPIED][0] = 2;

    dp[DOWN_OCCUPIED][NONE_OCCUPIED][0] = 3;
    dp[DOWN_OCCUPIED][UP_OCCUPIED][0] = 2;
    dp[DOWN_OCCUPIED][DOWN_OCCUPIED][0] = 2;
    dp[DOWN_OCCUPIED][BOTH_OCCUPIED][0] = 2;
    
    dp[BOTH_OCCUPIED][NONE_OCCUPIED][0] = 4;
    dp[BOTH_OCCUPIED][UP_OCCUPIED][0] = 3;
    dp[BOTH_OCCUPIED][DOWN_OCCUPIED][0] = 3;
    dp[BOTH_OCCUPIED][BOTH_OCCUPIED][0] = 2;

    for (int option=0; option<4; option++) {
        for (int i=1; i<N; i++) {
            dp[option][NONE_OCCUPIED][i] = 2 + min({
                dp[option][NONE_OCCUPIED][i-1],
                dp[option][UP_OCCUPIED][i-1],
                dp[option][DOWN_OCCUPIED][i-1],
                dp[option][BOTH_OCCUPIED][i-1]
            });

            dp[option][UP_OCCUPIED][i] = 1 + min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[i-1].first + enemy[i].first > W),
                dp[option][DOWN_OCCUPIED][i-1] + (enemy[i-1].first + enemy[i].second > W)
            });

            dp[option][DOWN_OCCUPIED][i] = 1 + min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[i-1].second + enemy[i].second > W),
                dp[option][UP_OCCUPIED][i-1] + (enemy[i-1].second + enemy[i].second > W)
            });

            dp[option][BOTH_OCCUPIED][i] = min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[i-1].first + enemy[i].first > W) + (enemy[i-1].second + enemy[i].second > W),
                dp[option][NONE_OCCUPIED][i-1] + (enemy[i].first + enemy[i].second > W),
                dp[option][UP_OCCUPIED][i-1] + (enemy[i].first + enemy[i].second > W),
                dp[option][DOWN_OCCUPIED][i-1] + (enemy[i].first + enemy[i].second > W),
                dp[option][BOTH_OCCUPIED][i-1] + (enemy[i].first + enemy[i].second > W)
            });
        }
    }

    result = min(result, min({
        dp[NONE_OCCUPIED][NONE_OCCUPIED][N-1],
        dp[NONE_OCCUPIED][UP_OCCUPIED][N-1],
        dp[NONE_OCCUPIED][DOWN_OCCUPIED][N-1],
        dp[NONE_OCCUPIED][BOTH_OCCUPIED][N-1],
    }));

    result = min(result, min({
        dp[UP_OCCUPIED][NONE_OCCUPIED][N-1] - (enemy[0].first + enemy[N-1].first <= W),
        dp[UP_OCCUPIED][UP_OCCUPIED][N-1],
        dp[UP_OCCUPIED][DOWN_OCCUPIED][N-1] - (enemy[0].first + enemy[N-1].first <= W),
        dp[UP_OCCUPIED][BOTH_OCCUPIED][N-1],
    }));

    result = min(result, min({
        dp[DOWN_OCCUPIED][NONE_OCCUPIED][N-1] - (enemy[0].second + enemy[N-1].second <= W),
        dp[DOWN_OCCUPIED][UP_OCCUPIED][N-1] - (enemy[0].second + enemy[N-1].second <= W),
        dp[DOWN_OCCUPIED][DOWN_OCCUPIED][N-1],
        dp[DOWN_OCCUPIED][BOTH_OCCUPIED][N-1],
    }));
    
    result = min(result, min({
        dp[BOTH_OCCUPIED][NONE_OCCUPIED][N-1] - (enemy[0].first + enemy[N-1].first <= W) - (enemy[0].second + enemy[N-1].second <= W),
        dp[BOTH_OCCUPIED][UP_OCCUPIED][N-1],
        dp[BOTH_OCCUPIED][DOWN_OCCUPIED][N-1],
        dp[BOTH_OCCUPIED][BOTH_OCCUPIED][N-1],
    }));

    cout << result << '\n';
}