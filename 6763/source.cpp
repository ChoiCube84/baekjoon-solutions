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
	
	ll limit, speed;
	cin >> limit >> speed;
	
	ll diff = speed - limit;
	ll fee = 0;
	
	if (diff <= 0) {
		cout << "Congratulations, you are within the speed limit!";
		return 0;
	}
	else if (diff < 21) {
		fee = 100;
	}
	else if (diff < 31) {
		fee = 270;
	}
	else {
		fee = 500;
	}
	
	cout << "You are speeding and your fine is $" << fee << ".";
	
	return 0;
}