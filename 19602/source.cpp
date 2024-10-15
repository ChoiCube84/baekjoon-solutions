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
	
	ll S, M, L;
	cin >> S >> M >> L;
	
	if (S + M * 2 + L * 3 < 10) {
		cout << "sad";
	}
	else {
		cout << "happy";
	}
	
	return 0;
}