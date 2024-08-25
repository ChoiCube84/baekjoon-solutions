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

	vector<vector<string>> colors(10, vector<string>(10));

	for (ll i=0; i<10; i++) {
		for (ll j=0; j<10; j++) {
			cin >> colors[i][j];
		}
	}

	bool found = false;

	for (ll i=0; i<10; i++) {
		bool check = true;
		for (ll j=1; j<10; j++) {
			if (colors[i][j-1] != colors[i][j]) {
				check = false;
				break;
			}
		}

		if (check) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << 1;
		return 0;
	}

	for (ll j=0; j<10; j++) {
		bool check = true;
		for (ll i=1; i<10; i++) {
			if (colors[i-1][j] != colors[i][j]) {
				check = false;
				break;
			}
		}

		if (check) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << 1;
		return 0;
	}

	cout << 0;

	return 0;
}