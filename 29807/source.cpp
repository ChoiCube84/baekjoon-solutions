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
	
	ll T;
	cin >> T;
	
	vector<ll> scores(5, 0);
	for (ll i=0; i<T; i++) {
		cin >> scores[i];
	}
	
	ll value1 = scores[0] - scores[2];
	ll value2 = scores[1] - scores[3];
	ll value3 = scores[4] * 707;
	
	if (scores[0] > scores[2]) {
		value1 *= 508;
	}
	else {
		value1 *= -108;
	}
	
	if (scores[1] > scores[3]) {
		value2 *= 212;
	}
	else {
		value2 *= -305;
	}
	
	cout << (value1 + value2 + value3) * 4763;
	
	return 0;
}