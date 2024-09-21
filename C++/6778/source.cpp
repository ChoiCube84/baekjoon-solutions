#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll antenna_count, eye_count;
    cin >> antenna_count >> eye_count;

    if (antenna_count >= 3 && eye_count <= 4) {
        cout << "TroyMartian" << '\n';
    }
    if (antenna_count <= 6 && eye_count >= 2) {
        cout << "VladSaturnian" << '\n';
    }
    if (antenna_count <= 2 && eye_count <= 3) {
        cout << "GraemeMercurian" << '\n';
    }

    return 0;
}