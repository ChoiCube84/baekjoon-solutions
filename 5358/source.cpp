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
		for (auto& c : input) {
			switch (c) {
				case 'i':
					cout << 'e';
					break;
				case 'e':
					cout << 'i';
					break;
				case 'I':
					cout << 'E';
					break;
				case 'E':
					cout << 'I';
					break;
				default:
					cout << c;
					break;
			}
		}
		cout << '\n';
	}
	
	return 0;
}