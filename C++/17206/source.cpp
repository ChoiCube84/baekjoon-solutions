#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int i=0; i<T; i++) {
		ll N;
		cin >> N;

		ll result = 0;

		for (ll i=3; i<=N; i+=3) {
			result += i;
		}

		for (ll i=7; i<=N; i+=7) {
			result += i;
		}

		for (ll i=21; i<=N; i+=21) {
			result -= i;
		}

		cout << result << '\n';
	}

	return 0;
}