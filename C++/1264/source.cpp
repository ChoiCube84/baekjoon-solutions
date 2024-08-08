#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;

	while (true) {
		getline(cin, input);
		
		if (input == "#") {
			break;
		}

		int count = 0;
		for (auto& c : input) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
				|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				count++;
			}
		}

		cout << count << '\n';
	}
	
	return 0;
}