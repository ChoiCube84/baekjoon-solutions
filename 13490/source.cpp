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
	
	ll K;
	cin >> K;
	
	for (ll t=1; t<=K; t++) {
		ll n, m;
		cin >> n >> m;
		
		vector<ll> x(m);
		for (ll i=0; i<m; i++) {
			cin >> x[i];
		}
		
		cout << "Data Set " << t << ": " << '\n';
	
		vector<ll> score(n);
		for (ll i=0; i<n; i++) {
			vector<ll> y(m);
			ll sum = 0;
			
			for (ll j=0; j<m; j++) {
				cin >> y[j];
				sum += x[j] * y[j];
			}
			
			score[i] = sum;
		}
		
		ll maximum = *max_element(score.begin(), score.end());
		
		for (ll i=0; i<n; i++) {
			if (score[i] == maximum) {
				cout << i+1 << '\n';
			}
		}
		
		cout << '\n';
	}
	
	return 0;
}