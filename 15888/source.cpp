#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

bool IsPowerOf2(ll num);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll A, B, C;
	cin >> A >> B >> C;
	
	if (A < 0) {
		A *= -1;
		B *= -1;
		C *= -1;
	}
	
	if (B % A != 0 || C % A != 0) {
		cout << "둘다틀렸근";
	}
	else {
		B /= A;
		C /= A;
		A = 1;
		
		for (ll i=-100; i<101; i++) {
			for (ll j=-100; j<101; j++) {
				if (i == j) {
					continue;
				}
				if (i + j == -1LL * B && i * j == C) {
					if (IsPowerOf2(i) && IsPowerOf2(j)) {
						cout << "이수근";
						return 0;
					}
					else {
						cout << "정수근";
						return 0;
					}
				}
			}
		}
		
		cout << "둘다틀렸근";
	}
	
	return 0;
}

bool IsPowerOf2(ll num) {
	ll powered = 2;

	while (powered <= num) {
		if (powered == num) {
			return true;
		}
		else {
			powered *= 2;
		}
	}
	
	return false;
}