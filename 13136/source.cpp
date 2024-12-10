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
	
	ll R, C, N;
	cin >> R >> C >> N;
	
	cout << ((R / N) + (R % N == 0 ? 0 : 1)) * ((C / N) + (C % N == 0 ? 0 : 1));
	
	return 0;
}