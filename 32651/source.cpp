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
	
	if (N <= 100000 && N % 2024 == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	
	return 0;
}