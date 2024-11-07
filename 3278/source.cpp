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
	
	vector<ld> B(N);
	vector<ld> S(N);
	
	vector<ld> dp_mark(N, 100L);
	vector<ld> dp_dollar(N, 0L);
	
	for (ll i=0; i<N; i++) {
		cin >> B[i] >> S[i];
		
		B[i] /= 100L;
		S[i] /= 100L;
	}
	
	dp_dollar[0] = B[0] * 100L;
	
	for (ll i=0; i<N; i++) {
		for (ll j=0; j<i; j++) {
			dp_mark[i] = max<ld>({dp_mark[i], dp_mark[j], dp_dollar[j] / S[i]});
			dp_dollar[i] = max<ld>({dp_dollar[i], dp_dollar[j], dp_mark[j] * B[i]});
		}
	}
	
	cout << fixed;
	cout.precision(2);
	
	cout << dp_mark[N-1];
	
	return 0;
}