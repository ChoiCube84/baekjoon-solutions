#include <bits/stdc++.h>

using namespace std;

int arr[1025][1025] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[j][i] += arr[j][i - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << arr[x2][y2] - (arr[x1 - 1][y2] + arr[x2][y1 - 1] - arr[x1 - 1][y1 - 1]) << "\n";
	}

	return 0;
}
