#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;

using pll = pair<ll, ll>;

vector<ll> getResult(const vector<ll>& players, string friendInfo, char myInfo);
bool friendWin(char friendRSP, char myRSP);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, M, K;
	cin >> N >> M >> K;

	vector<string> estimate(M);

	for (ll i=0; i<N; i++) {
		string input;
		cin >> input;

		ll rounds = 0;
		for (auto& c : input) {
			estimate[rounds] += c;
			rounds++;
		}
	}

	vector<ll> players(N);
	for (ll i=0; i<N; i++) {
		players[i] = i;
	}

	queue<pair<pair<ll, vector<ll>>, string>> q;
	q.push(make_pair(make_pair(0, players), ""));

	while (!q.empty()) {
		auto temp = q.front();
		auto temp2 = temp.first;

		auto rounds = temp2.first;
		auto currentPlayers = temp2.second;

		auto myHistory = temp.second;

		q.pop();

		if (currentPlayers.size() == 0) {
			continue;
		}
		else if (currentPlayers.size() <= K) {
			cout << rounds << '\n';
			cout << myHistory;

			return 0;
		}
		else if (rounds < M) {
			q.push(make_pair(make_pair(rounds + 1, getResult(currentPlayers, estimate[rounds], 'R')), myHistory + 'R'));
			q.push(make_pair(make_pair(rounds + 1, getResult(currentPlayers, estimate[rounds], 'S')), myHistory + 'S'));
			q.push(make_pair(make_pair(rounds + 1, getResult(currentPlayers, estimate[rounds], 'P')), myHistory + 'P'));
		}
	}

	cout << -1;

	return 0;
}

vector<ll> getResult(const vector<ll>& players, string friendInfo, char myInfo) {
	vector<ll> result;

	for (auto player : players) {
		if (friendWin(friendInfo[player], myInfo)) {
			result.push_back(player);
		}
	}

	return result;
}

bool friendWin(char friendRSP, char myRSP) {
	if (friendRSP == 'R') {
		if (myRSP == 'S') {
			return true;
		}
	}
	else if (friendRSP == 'S') {
		if (myRSP == 'P') {
			return true;
		}
	}
	else {
		if (myRSP == 'R') {
			return true;
		}
	}

	return false;
}