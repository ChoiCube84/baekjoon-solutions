#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

void fireWeakening(vector<int>& F);
int possibleCases(vector<int>& F, int W, int T, int K, int prevW, int currentTime);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, T, K;
    cin >> N >> W >> T >> K;

    vector<int> F(N, 0);
    for (int i=0; i<N; i++) {
        cin >> F[i];
    }

    int left = possibleCases(F, W - 1, T, K, -1, 1);
    int middle = possibleCases(F, W, T, K, -1, 1);
    int right = possibleCases(F, W + 1, T, K, -1, 1);

    cout << left + middle + right << "\n";

    return 0;
}

void fireWeakening(vector<int>& F, int fixedIndex) {
    int N = F.size();
    vector<int> newF = F;

    if (N > 1) {
        if (fixedIndex != 0) {
            newF[0] -= 3;
            newF[0] += (F[1] > 0);
            newF[0] = max(0, newF[0]);
        }
        for (int i=1; i<N-1; i++) {
            if (fixedIndex == i) {
                continue;
            }
            newF[i] -= 3;
            newF[i] += ((F[i-1] > 0) + (F[i+1] > 0));
            newF[i] = max(0, newF[i]);
        }
        if (fixedIndex != N-1) {
            newF[N-1] -= 3;
            newF[N-1] += (F[N-2] > 0);
            newF[N-1] = max(0, newF[N-1]);
        }
    }
    else {
        if (fixedIndex != 0) {
            newF[0] -= 3;
            newF[0] = max(0, newF[0]);
        }
    }

    F = newF;
}

int possibleCases(vector<int>& F, int W, int T, int K, int prevW, int currentTime) {
    int N = F.size();

    fireWeakening(F, prevW);

    if (W < 0 || W > N - 1) {
        return 0;
    }
    else if (currentTime + 1 == T) {
        return possibleCases(F, W, T, K, W, currentTime+1);
    }
    else if (currentTime == T) {
        int alive = 0;
        for (auto& f : F) {
            if (f > 0) {
                alive++;
            }
        }
        return (alive >= K);
    }
    else {
        vector<int> leftF = F;
        vector<int> middleF = F;
        vector<int> rightF = F;

        int left = possibleCases(leftF, W - 1, T, K, W, currentTime+1);
        int middle = possibleCases(middleF, W, T, K, W, currentTime+1);
        int right = possibleCases(rightF, W + 1, T, K, W, currentTime+1);

        return left + middle + right;
    }
}