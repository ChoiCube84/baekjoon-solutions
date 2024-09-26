#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		int X, Y;
		cin >> X >> Y;

		if (X < Y) {
			cout << "NO BRAINS\n";
		}
		else {
			cout << "MMM BRAINS\n";
		}
	}
	
	return 0;
}