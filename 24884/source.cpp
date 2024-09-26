#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int countFire(const vector<int>& F);
void fireWeakening(vector<int>& F, int fixedIndex);
void search(vector<int> F, int W, int T, int K, int fixedIndex, int currentTime, int& result);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, T, K, result = 0;
    cin >> N >> W >> T >> K;

    vector<int> F(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    search(F, W, T, K, -1, 1, result);

    cout << result;

    return 0;
}

void fireWeakening(vector<int>& F, int fixedIndex) {
    int N = F.size();
    vector<int> decrease(N, 0);

    for (int i=0; i<N; i++) {
        if (F[i] > 0 && i != fixedIndex) {
            decrease[i] = 3;
            if (i>0 && F[i-1] > 0) {
                decrease[i]--;
            }
            if (i<N-1 && F[i+1] > 0) {
                decrease[i]--;
            }
        }
    }

    for (int i=0; i<N; i++) {
        F[i] -= decrease[i];
        F[i] = max(0, F[i]);
    }
}

int countFire(const vector<int>& F) {
    return count_if(F.begin(), F.end(), [](int f) { return f > 0; });
}

void search(vector<int> F, int W, int T, int K, int fixedIndex, int currentTime, int& result) {
    int N = F.size();

    fireWeakening(F, fixedIndex);

    if (currentTime == T) {
        if (countFire(F) >= K) {
            result++;
        }
    }
    else {
        for (int newW = max(0, W-1); newW <= min(N-1, W+1); newW++) {
            search(F, newW, T, K, newW, currentTime + 1, result);
        }
    }
}