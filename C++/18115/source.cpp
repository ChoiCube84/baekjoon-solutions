#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	stack<ll> skills;
	
	for (ll i=0; i<N; i++) {
		ll temp;
		cin >> temp;

		skills.push(temp);
	}

	ll topCard = -1;
	deque<ll> cards;

	ll currentCard = 1;
	
	while (!skills.empty()) {
		ll skill = skills.top();
		skills.pop();

		switch (skill) {
		case 1:
			if (topCard != -1) {
				cards.push_front(topCard);
			}
			topCard = currentCard;
			break;
		case 2:
			cards.push_front(topCard);
			break;
		case 3:
			cards.push_back(topCard);
			break;
		}

		currentCard++;
	}

	cout << topCard << ' ';
	for (auto card : cards) {
		cout << card << ' ';
	}
	
	return 0;
}