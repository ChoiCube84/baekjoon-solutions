#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

pii previous[3];
pii current[3];

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < 3; i++) {
		cin >> previous[i].first;

		previous[i].second = previous[i].first;
		current[i] = previous[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> current[j].first;
			
			current[j].second = current[j].first;
		}

		current[0].first += min(previous[0].first, previous[1].first);
		current[0].second += max(previous[0].second, previous[1].second);

		current[1].first += min({ previous[0].first, previous[1].first, previous[2].first });
		current[1].second += max({ previous[0].second, previous[1].second, previous[2].second });

		current[2].first += min(previous[1].first, previous[2].first);
		current[2].second += max(previous[1].second, previous[2].second);

		for (int j = 0; j < 3; j++) {
			previous[j] = current[j];
		}
	}

	cout << max({ current[0].second, current[1].second, current[2].second }) << " " << min({ current[0].first, current[1].first, current[2].first });

	return 0;
}
