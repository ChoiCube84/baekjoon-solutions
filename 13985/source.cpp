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

	string input;
	getline(cin, input);

	int a = input[0] - '0';
	int b = input[4] - '0';
	int c = input[8] - '0';

	if (a + b == c) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}