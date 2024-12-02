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
	
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	
	C += D;
	
	B += C / 60;
	C %= 60;
	
	A += B / 60;
	B %= 60;
	
	A %= 24;
	
	cout << A << ' ' << B << ' ' << C;
	
	return 0;
}