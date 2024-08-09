#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int L, P;
	cin >> L >> P;

	for (int i=0; i<5; i++) {
		int temp;
		cin >> temp;

		cout << temp - L * P << ' ';
	}
	
	return 0;
}