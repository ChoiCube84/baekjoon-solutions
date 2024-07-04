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

    string dna;
    cin >> dna;

    int n = dna.size();

    vector<vector<bool>> isKOI(n, vector<bool>(n, false));)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int end=1; end<n; end++) {
        int maximum = 0;
        
        for (int start=0; start<end; start++) {
            if ()
        }
    }
    
    return 0;
}