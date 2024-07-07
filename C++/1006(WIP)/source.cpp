#include <bits/extc++.h>

#define NONE_OCCUPIED 0
#define UP_OCCUPIED 1
#define DOWN_OCCUPIED 2
#define BOTH_OCCUPIED 3

using namespace std;

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
    int N, W, result = INT_MAX;
    cin >> N >> W;

    vector<int> enemy[2];
    enemy[0].resize(N);
    enemy[1].resize(N);

    for (int i=0; i<N; i++) {
        cin >> enemy[0][i];
    }
    for (int i=0; i<N; i++) {
        cin >> enemy[1][i];
    }

    // First index: Connectedness of Start and End
    // Second index: Connectivity of current index
    // Third index: Current index considering the circle as a line

    vector<vector<vector<int>>> dp(4, vector<vector<int>>(4, vector<int>(N+1, INT_MAX)));

    for (int option=0; option<4; option++) {
        switch (option) {
        case NONE_OCCUPIED:
            dp[option][NONE_OCCUPIED][0] = 2;
            dp[option][UP_OCCUPIED][0] = 2;
            dp[option][DOWN_OCCUPIED][0] = 2;
            dp[option][BOTH_OCCUPIED][0] = 1 + (enemy[0][0] + enemy[1][0] > W);
            break;
        case UP_OCCUPIED:
            dp[option][NONE_OCCUPIED][0] = 3;
            dp[option][UP_OCCUPIED][0] = 2;
            dp[option][DOWN_OCCUPIED][0] = 2;
            dp[option][BOTH_OCCUPIED][0] = 2;
            break;
        case DOWN_OCCUPIED:
            dp[option][NONE_OCCUPIED][0] = 3;
            dp[option][UP_OCCUPIED][0] = 2;
            dp[option][DOWN_OCCUPIED][0] = 2;
            dp[option][BOTH_OCCUPIED][0] = 2;
            break;
        case BOTH_OCCUPIED:
            dp[option][NONE_OCCUPIED][0] = 4;
            dp[option][UP_OCCUPIED][0] = 3;
            dp[option][DOWN_OCCUPIED][0] = 3;
            dp[option][BOTH_OCCUPIED][0] = 2;
            break;
        }

        for (int i=1; i<N; i++) {
            dp[option][NONE_OCCUPIED][i] = 2 + min({
                dp[option][NONE_OCCUPIED][i-1],
                dp[option][UP_OCCUPIED][i-1],
                dp[option][DOWN_OCCUPIED][i-1],
                dp[option][BOTH_OCCUPIED][i-1]
            });

            dp[option][UP_OCCUPIED][0] = 1 + min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[0][i-1] + enemy[0][i] > W),
                dp[option][DOWN_OCCUPIED][i-1] + (enemy[0][i-1] + enemy[0][i] > W)
            });

            dp[option][DOWN_OCCUPIED][0] = 1 + min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[1][i-1] + enemy[1][i] > W),
                dp[option][UP_OCCUPIED][i-1] + (enemy[1][i-1] + enemy[1][i] > W)
            });

            dp[option][BOTH_OCCUPIED][0] = min({
                dp[option][NONE_OCCUPIED][i-1] + (enemy[0][i-1] + enemy[0][i] > W) + (enemy[1][i-1] + enemy[1][i] > W),
                dp[option][NONE_OCCUPIED][i-1] + (enemy[0][i] + enemy[1][i] > W),
                dp[option][UP_OCCUPIED][i-1] + (enemy[0][i] + enemy[1][i] > W),
                dp[option][DOWN_OCCUPIED][i-1] + (enemy[0][i] + enemy[1][i] > W),
                dp[option][BOTH_OCCUPIED][i-1] + (enemy[0][i] + enemy[1][i] > W)
            });
        }

        switch (option) {
        case NONE_OCCUPIED:
            result = min(result, min({
                dp[option][NONE_OCCUPIED][N-1],
                dp[option][UP_OCCUPIED][N-1],
                dp[option][DOWN_OCCUPIED][N-1],
                dp[option][BOTH_OCCUPIED][N-1],
            }));
            break;
        case UP_OCCUPIED:
            result = min(result, min({
                dp[option][NONE_OCCUPIED][N-1] - (enemy[0][0] + enemy[0][N-1] <= W),
                dp[option][UP_OCCUPIED][N-1],
                dp[option][DOWN_OCCUPIED][N-1] - (enemy[0][0] + enemy[0][N-1] <= W),
                dp[option][BOTH_OCCUPIED][N-1],
            }));
            break;
        case DOWN_OCCUPIED:
            result = min(result, min({
                dp[option][NONE_OCCUPIED][N-1] - (enemy[1][0] + enemy[1][N-1] <= W),
                dp[option][UP_OCCUPIED][N-1] - (enemy[1][0] + enemy[1][N-1] <= W),
                dp[option][DOWN_OCCUPIED][N-1],
                dp[option][BOTH_OCCUPIED][N-1],
            }));
            break;
        case BOTH_OCCUPIED:
            result = min(result, min({
                dp[option][NONE_OCCUPIED][N-1] - (enemy[0][0] + enemy[0][N-1] <= W) - (enemy[1][0] + enemy[1][N-1] <= W),
                dp[option][UP_OCCUPIED][N-1],
                dp[option][DOWN_OCCUPIED][N-1],
                dp[option][BOTH_OCCUPIED][N-1],
            }));
            break;
        }
    }

    cout << result << "\n";
}