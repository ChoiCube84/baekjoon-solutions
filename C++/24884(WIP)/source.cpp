#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int countFire(const vector<int>& F);
void fireWeakening(vector<int>& F, int fixedIndex);
int possibleCases(vector<int> F, int W, int T, int K, int prevW, int currentTime);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, T, K;
    cin >> N >> W >> T >> K;

    vector<int> F(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    cout << possibleCases(F, W, T, K, -1, 1);

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

int possibleCases(vector<int> F, int W, int T, int K, int prevW, int currentTime) {
    int N = F.size();

    fireWeakening(F, prevW);

    if (W < 0 || W > N - 1) {
        return 0;
    } 
    else if (currentTime == T) {
        int alive = countFire(F);
        return (alive >= K) ? 1 : 0;
    } 
    else {
        int left = possibleCases(F, W - 1, T, K, W, currentTime + 1);
        int middle = possibleCases(F, W, T, K, W, currentTime + 1);
        int right = possibleCases(F, W + 1, T, K, W, currentTime + 1);

        return left + middle + right;
    }
}