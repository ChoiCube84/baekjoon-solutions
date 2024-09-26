#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	if (T == 1) {
		ull A, B, C;
		cin >> A >> B;

		C = A + B;

		string result;

		while (C > 0) {
			result = static_cast<char>(C % 26 + 'a') + result;
			C /= 26;
		}

		while (result.length() < 13) {
			result = 'a' + result;
		}

		cout << result;
	}
	else {
		string input;
		cin >> input;

		ull result = 0;

		for (auto& c : input) {
			result = result * 26 + (c - 'a');
		}

		cout << result;
	}

	return 0;
}