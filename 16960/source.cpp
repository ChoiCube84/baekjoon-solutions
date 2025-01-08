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
	
	ll N, M;
	cin >> N >> M;
	
	vector<ll> lamp(M+1, 0);
	vector<vector<ll>> buttons(N);
	
	for (ll i=0; i<N; i++) {
		ll count;
		cin >> count;
		
		for (ll j=0; j<count; j++) {
			ll connect;
			cin >> connect;
			
			lamp[connect]++;
			buttons[i].emplace_back(connect);
		}
	}
	
	ll success = false;
	for (ll i=0; i<N; i++) {
		bool off_found = false;
		auto lamp_off = lamp;
		
		for (auto& connect : buttons[i]) {
			lamp_off[connect]--;
		}
		
		for (ll j=1; j<=M; j++) {
			if (lamp_off[j] == 0) {
				off_found = true;
				break;
			}
		}
		
		if (!off_found) {
			success = true;
			break;
		}
	}
	
	if (success) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	return 0;
}