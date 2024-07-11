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

    ull N;
    cin >> N;

    vector<ull> M(N, 0);
    for (ull i=0; i<N; i++) {
        cin >> M[i];
    }

    sort(M.begin(), M.end());

    ull result = 1;
    for (ull i=0; i<N; i++) {
        if (M[i] > result) {
            break;
        }
        result += M[i];
    }

    cout << result;

    return 0;
}