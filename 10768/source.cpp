#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int month, day;
	cin >> month >> day;

	if (month < 2) {
		cout << "Before";
	}
	else if (month == 2) {
		if (day < 18) {
			cout << "Before";
		}
		else if (day == 18) {
			cout << "Special";
		}
		else {
			cout << "After";
		}
	}
	else {
		cout << "After";
	}
	
	return 0;
}