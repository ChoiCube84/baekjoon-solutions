#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N;
	cin >> N;
	
	vector<string> files(N);
	for (ll i=0; i<N; i++) {
		cin >> files[i];
	}
	
	string result;
	
	for (ll i=0; i<files[0].size(); i++) {
		bool all_same = true;
		
		for (ll j=1; j<N; j++) {
			if (files[0][i] != files[j][i]) {
				all_same = false;
				break;
			}
		}
		
		if (all_same) {
			result += files[0][i];
		}
		else {
			result += '?';
		}
	}
	
	cout << result;
	
	return 0;
}