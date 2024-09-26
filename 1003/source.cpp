#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

pll fibo(int n);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    
    vector<int> N(T);
    for (int i=0; i<T; i++) {
        cin >> N[i];
    }

    for (auto n : N) {
        auto result = fibo(n);
        cout << result.first << " " << result.second << '\n';
    }

    return 0;
}

pll fibo(int n) {
    vector<pll> dp;

    pll prev = make_pair(1, 0);
    pll curr = make_pair(0, 1);
    
    if (n == 0) {
        return prev;
    }
    else {
        for (int i=1; i<n; i++) {
            int zeroCount = prev.first + curr.first;
            int oneCount = prev.second + curr.second;

            prev = curr;
            curr = make_pair(zeroCount, oneCount);
        }

        return curr;
    }
}