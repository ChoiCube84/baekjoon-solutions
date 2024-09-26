#include <bits/stdc++.h>

using namespace std;

pair<bool, int> visited[100001];

int w[3] = { 1, 1, 2 };
int b[3] = { -1, 1, 0 };

bool isInRange(int position);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int shortest = INT_MAX;
	int shortestCount = 0;

	queue<pair<int, int>> q;

	cin >> N >> K;

	q.push({ N, 0 });
	visited[N] = make_pair(true, 0);

	while (!q.empty()) {
		pair<int, int> currentPoint = q.front();
		q.pop();

		if (currentPoint.second > shortest) {
			continue;
		}
		else if (currentPoint.first == K) {
			if (currentPoint.second < shortest) {
				shortest = currentPoint.second;
				shortestCount = 1;
			}
			else if (currentPoint.second == shortest) {
				shortestCount++;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				int newPosition = w[i] * currentPoint.first + b[i];

				if (isInRange(newPosition) && (visited[newPosition].first == false || newPosition == K || visited[newPosition].second == currentPoint.second + 1)) {
					q.push({ newPosition , currentPoint.second + 1 });
					visited[newPosition] = make_pair(true, currentPoint.second + 1);
				}
			}
		}
	}

	cout << shortest << "\n";
	cout << shortestCount;

	return 0;
}

bool isInRange(int position) {
	if (position < 0 || position > 100000) {
		return false;
	}
	else {
		return true;
	}
}
