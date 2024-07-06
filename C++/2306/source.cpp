#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

bool matchedDNA(char a, char b);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string dna;
    cin >> dna;

    int n = dna.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int end=1; end<n; end++) {
        for (int start=end-1; start>=0; start--) {
            if (matchedDNA(dna[start], dna[end])) {
                dp[start][end] = dp[start+1][end-1] + 2;
            }

            for (int middle=start; middle<end; middle++) {
                dp[start][end] = max(dp[start][end], dp[start][middle] + dp[middle+1][end]);
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}

bool matchedDNA(char a, char b) {
    return (a == 'a' && b == 't') || (a == 'g' && b == 'c');
}