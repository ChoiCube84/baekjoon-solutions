#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

int bishopCount(int N, const vector<pair<int, int>> &availablePoints, ull &lineOccupied, int start);
pair<int, int> positionToLineNum(const pair<int, int>& curr, int N);
bool check(const pair<int, int>& curr, int N, ull lineOccupied);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> whitePoints;
    vector<pair<int, int>> blackPoints;

    ull lineOccupied = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int status;
            cin >> status;

            if (status == 1) {
                if ((i + j) % 2 == 0) {
                    whitePoints.emplace_back(i, j);
                }
                else {
                    blackPoints.emplace_back(i, j);
                }
            }
        }
    }

    int whiteBishopCount = bishopCount(N, whitePoints, lineOccupied, 0);
    int blackBishopCount = bishopCount(N, blackPoints, lineOccupied, 0);

    cout << whiteBishopCount + blackBishopCount;

    return 0;
}

int bishopCount(int N, const vector<pair<int, int>> &availablePoints, ull &lineOccupied, int start) {
    int maximum = 0;

    for (int curr=start; curr<availablePoints.size(); curr++) {
        if (check(availablePoints[curr], N, lineOccupied)) {
            pair<int, int> lines = positionToLineNum(availablePoints[curr], N);

            ull mask1 = 1ULL << lines.first;
            ull mask2 = 1ULL << lines.second;

            lineOccupied ^= mask1;
            lineOccupied ^= mask2;

            maximum = max(maximum, 1 + bishopCount(N, availablePoints, lineOccupied, curr + 1));

            lineOccupied ^= mask1;
            lineOccupied ^= mask2;
        }
    }

    return maximum;
}

pair<int, int> positionToLineNum(const pair<int, int>& curr, int N) {
    return make_pair(curr.first + curr.second, 3 * N - 2 + curr.first - curr.second);
}

bool check(const pair<int, int>& curr, int N, ull lineOccupied) {
    pair<int, int> lines = positionToLineNum(curr, N);

    if ((lineOccupied & (1ULL << lines.first)) || (lineOccupied & (1ULL << lines.second))) {
        return false;
    }
    else {
        return true;
    }
}
