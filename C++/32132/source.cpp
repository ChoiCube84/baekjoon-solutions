#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;

using pll = pair<ll, ll>;

bool checkPlayStation(string input);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	string input;
	cin >> input;

	string result;

	bool foundP = false;
	bool foundS = false;

	for (char c : input) {
		if (c == 'P') {
			foundP = true;
			foundS = false;
		}
		else if (foundP) {
			if (foundS) {
				if (c == '4' || c == '5') {
					continue;
				}
				else if (c == 'P') {
					foundS = false;
				}
				else {
					foundP = false;
					foundS = false;
				}
			}
			else if (c == 'S') {
				foundS = true;
			}
			else {
				foundP = false;
			}
		}

		result += c;
	}

	cout << result;

	return 0;
}