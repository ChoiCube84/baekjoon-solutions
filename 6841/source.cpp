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
		
	while (true) {
		cin >> input;
		
		if (input == "CU") {
			cout << "see you" << '\n';
		}
		else if (input == ":-)") {
			cout << "I’m happy" << '\n';
		}
		else if (input == ":-(") {
			cout << "I’m unhappy" << '\n';
		}
		else if (input == ";-)") {
			cout << "wink" << '\n';
		}
		else if (input == ":-P") {
			cout << "stick out my tongue" << '\n';
		}
		else if (input == "(~.~)") {
			cout << "sleepy" << '\n';
		}
		else if (input == "TA") {
			cout << "totally awesome" << '\n';
		}
		else if (input == "CCC") {
			cout << "Canadian Computing Competition" << '\n';
		}
		else if (input == "CUZ") {
			cout << "because" << '\n';
		}
		else if (input == "TY") {
			cout << "thank-you" << '\n';
		}
		else if (input == "YW") {
			cout << "you\'re welcome" << '\n';
		}
		else if (input == "TTYL") {
			cout << "talk to you later";
			break;
		}
		else {
			cout << input << '\n';
		}
	}	
	
	return 0;
}