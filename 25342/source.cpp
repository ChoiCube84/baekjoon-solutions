#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long int;
using ull = unsigned long long int;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

ull tripleLCM(ull a, ull b, ull c);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        int N;
        cin >> N;

        cout << max({
            tripleLCM(N, N-1, N-2), tripleLCM(N, N-1, N-3), 
            tripleLCM(N, N-2, N-3), tripleLCM(N-1, N-2, N-3)
        }) << "\n";
    }

    return 0;
}

ull tripleLCM(ull a, ull b, ull c) {
    ull result = lcm(a, b);
    result = lcm(result, c);

    return result;
}