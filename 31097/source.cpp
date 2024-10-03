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
	cin >> input;
	
	ll month = (input[5] - '0') * 10 + (input[6] - '0');
	ll day = (input[8] - '0') * 10 + (input[9] - '0');
	
	ll date = month * 100 + day;
	
	if (date >= 1222 || date <= 119) {
		cout << "Capricorn";
	}
	else if (date <= 218) {
		cout << "Aquarius";
	}
	else if (date <= 320) {
		cout << "Pisces";
	}
	else if (date <= 419) {
		cout << "Aries";
	}
	else if (date <= 520) {
		cout << "Taurus";
	}
	else if (date <= 620) {
		cout << "Gemini";
	}
	else if (date <= 722) {
		cout << "Cancer";
	}
	else if (date <= 822) {
		cout << "Leo";
	}
	else if (date <= 922) {
		cout << "Virgo";
	}
	else if (date <= 1022) {
		cout << "Libra";
	}
	else if (date <= 1122) {
		cout << "Scorpio";
	}
	else {
		cout << "Sagittarius";
	}
	
	return 0;
}