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

    long double A, B;
    cin >> A >> B;

    long double c = 299792458;

    cout << setprecision(15) << (A + B) / (1 + (A * B) / (c * c));
    
    return 0;
}