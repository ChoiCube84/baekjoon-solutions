#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] = abs(A[i]);
    }

    vector<bool> prev(1024, false);
    vector<bool> curr(1024, false);

    for (auto& a : A) {
        prev[a] = true;
    }
    
    for (int i=1; i<M; i++) {
        for (auto& a : A) {
            for (int j=0; j<1024; j++) {
                if (prev[j]) {
                    curr[j ^ a] = true;
                }
            }
        }
        prev = curr;
        for (int j=0; j<1024; j++) {
            curr[j] = false;
        }
    }

    int maximum = 0;
    for (int i=0; i<1024; i++) {
        if (prev[i]) {
            maximum = i;
        }
    }

    cout << maximum;

    return 0;
}