#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int combineCoordinates(int A, int B);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(10000, 0));

    dp[0][0] = 1;

    dp[1][combineCoordinates(0, 1)] = 1;
    dp[1][combineCoordinates(1, 0)] = 1;
    
    for (int i=2; i<n; i++) {
        for (int A=0; A<=i; A++) {
            for (int B=0; B<=i; B++) {
                if (A != B) {
                    dp[i][combineCoordinates(A, B)] += dp[i-1][combineCoordinates(A, B)];

                    if (B > 0) {
                        dp[i][combineCoordinates(A, B)] += dp[i-1][combineCoordinates(A, B-1)];
                    }

                    if (A > 0) {
                        dp[i][combineCoordinates(A, B)] += dp[i-1][combineCoordinates(A-1, B)];

                        if (B > 0) {
                            dp[i][combineCoordinates(A, B)] += dp[i-1][combineCoordinates(A-1, B-1)];
                        }
                    }
                }

                dp[i][combineCoordinates(A, B)] %= 10007;
            }
        }
    }

    int result = 0;
    for (int A=0; A<n; A++) {
        for (int B=0; B<n; B++) {
            if (A != B) {
                result += dp[n-1][combineCoordinates(A, B)];
                result %= 10007;
            }
        }
    }

    cout << result;

    return 0;
}

int combineCoordinates(int A, int B) {
    return A * 100 + B;
}