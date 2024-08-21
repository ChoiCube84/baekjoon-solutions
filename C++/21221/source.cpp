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

	ll n, m;
	cin >> n >> m;

	vector<vector<bool>> result(n, vector<bool>(m, false));
	
	for (ll i=0; i<n; i++) {
		string input;
		cin >> input;

		for (ll j=0; j<m; j++) {
			if (input[j] == '#') {
				result[i][j] = result[i+1][j] = result[i][j+1] = result[i+1][j+1] = true;
			}
		}
	}

	for (ll i=0; i<n; i++) {
		for (ll j=0; j<m; j++) {
			if (result[i][j]) {
				cout << '#';
			}
			else {
				cout << '.';
			}
		}
		cout << '\n';
	}
	
	return 0;
}