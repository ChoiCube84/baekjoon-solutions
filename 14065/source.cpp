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

	long double gallon = 3.785411784L;
	long double mile = 1.609344L;

	long double x;
	cin >> x;

	cout << setprecision(15) << fixed << 100.0L / (x / gallon * mile);

	return 0;
}