#include <bits/extc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;

	int aeiouCount = 0;
	int yCount = 0;

	for (char c : input) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			aeiouCount++;
		}
		else if (c == 'y') {
			yCount++;
		}
	}

	cout << aeiouCount << ' ' << aeiouCount + yCount;

	return 0;
}