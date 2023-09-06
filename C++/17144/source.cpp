#include <bits/stdc++.h>

using namespace std;

int R, C;
int house[50][50] = { 0, };
int propagate[50][50] = { 0, };

pair<int, int> upperCleaner = make_pair(-1, -1);
pair<int, int> lowerCleaner = make_pair(-1, -1);

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void oneSecondLater(void);
void spread(void);
void cleanerWork(void);
bool isInRange(int r, int c);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> house[i][j];

			if (house[i][j] == -1) {
				if (upperCleaner.first == -1 && upperCleaner.second == -1) {
					upperCleaner = make_pair(i, j);
				}
				else {
					lowerCleaner = make_pair(i, j);
				}
			}
		}
	}

	for (int second = 0; second < T; second++) {
		oneSecondLater();
	}

	int answer = 2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			answer += house[i][j];
		}
	}

	cout << answer;

	return 0;
}

void oneSecondLater(void) {
	spread();
	cleanerWork();
}

void spread(void) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			propagate[i][j] = 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int dir = 0; dir < 4; dir++) {
				int newY = i + dy[dir];
				int newX = j + dx[dir];

				if (isInRange(newY, newX) == true && house[newY][newX] != -1) {
					propagate[newY][newX] += (house[i][j] / 5);
					propagate[i][j] -= (house[i][j] / 5);
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			house[i][j] += propagate[i][j];
		}
	}
}

void cleanerWork(void) {
	int dustToPush = 0;
	for (int column = 1; column < C; column++) {
		swap(dustToPush, house[upperCleaner.first][column]);
	}
	for (int row = upperCleaner.first - 1; row >= 0; row--) {
		swap(dustToPush, house[row][C - 1]);
	}
	for (int column = C - 2; column >= 0; column--) {
		swap(dustToPush, house[0][column]);
	}
	for (int row = 1; row < upperCleaner.first; row++) {
		swap(dustToPush, house[row][0]);
	}

	dustToPush = 0;
	for (int column = 1; column < C; column++) {
		swap(dustToPush, house[lowerCleaner.first][column]);
	}
	for (int row = lowerCleaner.first + 1; row < R; row++) {
		swap(dustToPush, house[row][C - 1]);
	}
	for (int column = C - 2; column >= 0; column--) {
		swap(dustToPush, house[R - 1][column]);
	}
	for (int row = R - 2; row > lowerCleaner.first; row--) {
		swap(dustToPush, house[row][0]);
	}
}

bool isInRange(int r, int c) {
	if (r < 0 || r > R - 1) {
		return false;
	}
	else if (c < 0 || c > C - 1) {
		return false;
	}
	else {
		return true;
	}
}
