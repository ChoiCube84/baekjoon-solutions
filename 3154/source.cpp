#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

ll effort(ll a, ll b);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input;
	cin >> input;
	
	ll minimum = LLONG_MAX;
	string result;
	
	for (ll hour = (input[0] - '0') * 10 + (input[1] - '0'); hour < 100; hour += 24) {
		for (ll minute = (input[3] - '0') * 10 + (input[4] - '0'); minute < 100; minute += 60) {
			ll candidate = effort(hour / 10, hour % 10) + effort(hour % 10, minute / 10) + effort(minute / 10, minute % 10);
			
			if (candidate < minimum) {
				minimum = candidate;
				
				if (hour < 10) {
					result = "0";
					result += to_string(hour);
				}
				else {
					result = to_string(hour);
				}
				result += ':';
				
				if (minute < 10) {
					result += '0';
				}
				result += to_string(minute);
			}
		}
	}
	
	cout << result;
	
	return 0;
}

ll effort(ll a, ll b) {
	vector<pll> pos = {make_pair(1, 3), 
					   make_pair(0, 0), make_pair(1, 0), make_pair(2, 0),
					   make_pair(0, 1), make_pair(1, 1), make_pair(2, 1),
					   make_pair(0, 2), make_pair(1, 2), make_pair(2, 2)};
	
	return abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
}