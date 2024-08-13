#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll T;
	cin >> T;

	long double PI = 3.141592653589793L;

	while (T--) {
		ll N, A, B;
		cin >> N >> A >> B;

		long double a = (2 * A) * PI;
		long double b = B * (N * sinl(2 * PI / N));

		if (a > b) {
			cout << floor((N * asinl(sqrtl(b / a)))/PI) + 1 << '\n';
		}
		else {
			cout << N << '\n';
		}
	}

	return 0;
}