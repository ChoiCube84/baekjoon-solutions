#include <bits/stdc++.h>

using namespace std;

int tomatoes[1000][1000] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int width, height, tempTomato;
	int timePassed = 0;

	pair<pair<int, int>, int> currentRipenTomato;
	queue<pair<pair<int, int>, int>> ripenTomatoes;

	cin >> width >> height;

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			cin >> tempTomato;
			tomatoes[i][j] = tempTomato;

			if (tempTomato == 1) {
				ripenTomatoes.push({ {i, j}, 0 });
			}
		}
	}

	while (!ripenTomatoes.empty()) {
		currentRipenTomato = ripenTomatoes.front();
		ripenTomatoes.pop();

		if (timePassed < currentRipenTomato.second) {
			timePassed = currentRipenTomato.second;
		}

		pair<int, int> currentRipenTomatoPosition = currentRipenTomato.first;

		if (currentRipenTomatoPosition.first > 0 && tomatoes[currentRipenTomatoPosition.first - 1][currentRipenTomatoPosition.second] == 0) {
			pair<int, int> newRipenTomatoPosition = { currentRipenTomatoPosition.first - 1, currentRipenTomatoPosition.second };
			tomatoes[newRipenTomatoPosition.first][newRipenTomatoPosition.second] = 1;
			ripenTomatoes.push({ newRipenTomatoPosition, currentRipenTomato.second + 1 });
		}

		if (currentRipenTomatoPosition.first < width - 1 && tomatoes[currentRipenTomatoPosition.first + 1][currentRipenTomatoPosition.second] == 0) {
			pair<int, int> newRipenTomatoPosition = { currentRipenTomatoPosition.first + 1, currentRipenTomatoPosition.second };
			tomatoes[newRipenTomatoPosition.first][newRipenTomatoPosition.second] = 1;
			ripenTomatoes.push({ newRipenTomatoPosition, currentRipenTomato.second + 1 });
		}

		if (currentRipenTomatoPosition.second > 0 && tomatoes[currentRipenTomatoPosition.first][currentRipenTomatoPosition.second - 1] == 0) {
			pair<int, int> newRipenTomatoPosition = { currentRipenTomatoPosition.first, currentRipenTomatoPosition.second - 1 };
			tomatoes[newRipenTomatoPosition.first][newRipenTomatoPosition.second] = 1;
			ripenTomatoes.push({ newRipenTomatoPosition, currentRipenTomato.second + 1 });
		}

		if (currentRipenTomatoPosition.second < height - 1 && tomatoes[currentRipenTomatoPosition.first][currentRipenTomatoPosition.second + 1] == 0) {
			pair<int, int> newRipenTomatoPosition = { currentRipenTomatoPosition.first, currentRipenTomatoPosition.second + 1 };
			tomatoes[newRipenTomatoPosition.first][newRipenTomatoPosition.second] = 1;
			ripenTomatoes.push({ newRipenTomatoPosition, currentRipenTomato.second + 1 });
		}
	}

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (tomatoes[i][j] == 0) {
				timePassed = -1;
				break;
			}
		}

		if (timePassed == -1) {
			break;
		}
	}

	cout << timePassed;

	return 0;
}
