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
	
	ll n;
	cin >> n;
	
	n--;
	
	cout << static_cast<char>('a' + (n % 8)) << (n / 8 + 1);
	
	return 0;
}