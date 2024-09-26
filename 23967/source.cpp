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

    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i=0; i<N; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        int result = 0;
        int currentYogurt = 0;
        int dayPassed = 0;

        bool fail = false;

        while (!fail) {
            for (int i=0; i<K; i++) {
                if (currentYogurt == N) {
                    fail = true;
                    break;
                }
                if (A[currentYogurt] > dayPassed) {
                    result++;
                    currentYogurt++;
                }
                else if (currentYogurt == N-1) {
                    fail = true;
                    break;
                }
                else {
                    i--;
                    currentYogurt++;
                }
            }
            dayPassed++;
        }

        cout << "Case #" << t << ": " << result << '\n';
    }

    return 0;
}