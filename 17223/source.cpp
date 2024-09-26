#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int makeEventName(int user, int event);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> eventCount(N, 0);
	gp_hash_table<int, vector<int>> table;

	for (int i=0; i<N; i++) {
		table[makeEventName(i, 0)] = vector<int>();
	}

	for (int m=0; m<M; m++) {
		int i, j;
		cin >> i >> j;

		table[makeEventName(j, eventCount[j]+1)].emplace_back(makeEventName(j, eventCount[j]));

		if (i != j) {
			table[makeEventName(j, eventCount[j]+1)].emplace_back(makeEventName(i, eventCount[i]));
		}
		
		eventCount[j]++;
	}

	int A, p, B, q;
	cin >> A >> p >> B >> q;

	bool found = false;
	
	std::queue<int> Q;
	Q.emplace(makeEventName(A, p));

	gp_hash_table<int, bool> visited;
	
	while (!Q.empty()) {
		int currEvent = Q.front();
		Q.pop();

		if (visited[currEvent]) {
			continue;
		}
		else {
			visited[currEvent] = true;
		}
		
		for (auto& next : table[currEvent]) {
			if (next == makeEventName(B, q)) {
				found = true;
				break;
			}
			else {
				Q.emplace(next);
			}
		}
	}

	cout << found;

	return 0;
}

int makeEventName(int user, int event) {
	return user * 100000 + event;
}