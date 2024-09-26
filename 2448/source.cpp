#include <bits/stdc++.h>

using namespace std;

char board[10000][10000] = { 0, };

void starSet(int size, int row, int column);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	starSet(N / 3, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N + 1; j++) {
			if (board[i][j] == '*') {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}

void starSet(int size, int row, int column) {
	if (size == 1) {
		board[row][column] = '*';
		board[row + 1][column - 1] = '*'; board[row + 1][column + 1] = '*';
		board[row + 2][column - 2] = '*'; board[row + 2][column - 1] = '*'; board[row + 2][column] = '*'; board[row + 2][column + 1] = '*'; board[row + 2][column + 2] = '*';
	}
	else {
		starSet(size / 2, row, column);
		starSet(size / 2, row + 3 * size / 2, column - 3 * size / 2);
		starSet(size / 2, row + 3 * size / 2, column + 3 * size / 2);
	}
}
