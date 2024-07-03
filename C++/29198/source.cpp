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

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> S(N); 
    for (int i=0; i<N; i++) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }

    sort(S.begin(), S.end());

    string result;
    for (int i=0; i<K; i++) {
        result += S[i];
    }

    sort(result.begin(), result.end());

    cout << result;
    
    return 0;
}