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
	
	string plain, encrypted;
	cin >> plain >> encrypted;
	
	ll N = plain.size();
	string key;
	
	for (ll i=0; i<N; i++) {
		key += static_cast<char>('A' + (encrypted[i] - plain[i] + 25) % 26);
	}
	
	for (ll i=1; i<N; i++) {
		if (N % i != 0) {
			continue;
		}
		
		ll pattern_length = i;
		bool found = true;
		
		for (ll pivot = 0; pivot < pattern_length; pivot++) {
			for (ll curr = pivot + pattern_length; curr < N; curr += pattern_length) {
				if (key[pivot] != key[curr]) {
					found = false;
					break;
				}
			}

			if (!found) {
				break;
			}
		}

		if (found) {
			for (ll j=0; j<pattern_length; j++) {
				cout << key[j];
			}
			return 0;
		}
	}
	
	cout << key;
	
	return 0;
}