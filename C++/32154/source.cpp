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

	ll N;
	cin >> N;

	switch (N) {
	case 1:
		cout << 11 << '\n' << "A B C D E F G H J L M";
		break;
	case 2:
	case 3:
		cout << 9 << '\n' << "A C E F G H I L M";
		break;
	case 4:
		cout << 9 << '\n' << "A B C E F G H L M";
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		cout << 8 << '\n' << "A C E F G H L M";
		break;
	case 10:
		cout << 8 << '\n' << "A B C F G H L M";
		break;
	}

	return 0;
}