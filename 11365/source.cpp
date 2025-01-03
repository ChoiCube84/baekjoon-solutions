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
	
	string input;
	while (getline(cin, input)) {
		if (input == "END") {
			break;
		}
		reverse(input.begin(), input.end());
		cout << input << '\n';
	}
	
	return 0;
}