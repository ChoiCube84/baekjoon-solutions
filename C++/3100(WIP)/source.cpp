#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<char>> flag(6, vector<char>(9));

    for (int i=0; i<6; i++) {
        string input;
        cin >> input;

        for (int j=0; j<9; j++) {
            flag[i][j] = input[j];
        }
    }

    int horizontalCount = INT_MAX;

    vector<int> centerCandidate(26, 0);
    for (int i=2; i<4; i++) {
        for (int j=0; j<9; j++) {
            centerCandidate[flag[i][j] - 'A']++;
        }
    }

    for (int c=0; c<26; c++) {
        if (centerCandidate[c] == 0) {
            continue;
        }

        int tempHorizontalCount = 18 - centerCandidate[c];

        vector<int> letterCount(26, 0);
        int best = 0;

        for (int i=0; i<2; i++) {
            for (int j=0; j<9; j++) {
                if (c != (flag[i][j] - 'A')) {
                    letterCount[flag[i][j] - 'A']++;
                    best = max(best, letterCount[flag[i][j] - 'A']);
                }
            }
        }

        tempHorizontalCount += (18 - best);

        for (int i=0; i<26; i++) {
            letterCount[i] = 0;
        }
        best = 0;

        for (int i=4; i<6; i++) {
            for (int j=0; j<9; j++) {
                if (c != (flag[i][j] - 'A')) {
                    letterCount[flag[i][j] - 'A']++;
                    best = max(best, letterCount[flag[i][j] - 'A']);
                }
            }
        }

        tempHorizontalCount += (18 - best);

        horizontalCount = min(horizontalCount, tempHorizontalCount);
    }

    int verticalCount = INT_MAX;

    for (int i=0; i<26; i++) {
        centerCandidate[i] = 0;
    }

    for (int i=0; i<6; i++) {
        for (int j=3; j<6; j++) {
            centerCandidate[flag[i][j] - 'A']++;
        }
    }

    for (int c=0; c<26; c++) {
        if (centerCandidate[c] == 0) {
            continue;
        }

        int tempVerticalCount = 18 - centerCandidate[c];

        vector<int> letterCount(26, 0);
        int best = 0;

        for (int i=0; i<6; i++) {
            for (int j=0; j<3; j++) {
                if (c != (flag[i][j] - 'A')) {
                    letterCount[flag[i][j] - 'A']++;
                    best = max(best, letterCount[flag[i][j] - 'A']);
                }
            }
        }

        tempVerticalCount += (18 - best);

        for (int i=0; i<26; i++) {
            letterCount[i] = 0;
        }
        best = 0;

        for (int i=0; i<6; i++) {
            for (int j=6; j<9; j++) {
                if (c != (flag[i][j] - 'A')) {
                    letterCount[flag[i][j] - 'A']++;
                    best = max(best, letterCount[flag[i][j] - 'A']);
                }
            }
        }

        tempVerticalCount += (18 - best);

        verticalCount = min(verticalCount, tempVerticalCount);
    }

    cout << horizontalCount << "\n" << verticalCount << "\n";

    cout << min(horizontalCount, verticalCount);

    return 0;
}