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

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int sum = A + B + C + D;
    
    cout << max({abs(sum - 2 * (A + B)), abs(sum - 2 * (A + C)), abs(sum - 2 * (A + D))});
    
    return 0;
}