#include <bits/stdc++.h>

using namespace std;

int evaluateGrid(int searchDepth, int(*paper)[501], int height, int width, pair<int, int> gridPosition, pair<int, int> prevGridPosition, pair<int, int> prevOfPrevGridPosition);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int height, width, tempValue;
	int paper[501][501] = { 0, };
	int maximum = 0;

	cin >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tempValue;
			paper[i][j] = tempValue;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int tempValue = evaluateGrid(1, paper, height, width, { i , j }, { -100, -100 }, { -200, -200 });
			if (maximum < tempValue) {
				maximum = tempValue;
			}
		}
	}

	cout << maximum;

	return 0;
}

int evaluateGrid(int searchDepth, int(*paper)[501], int height, int width, pair<int, int> gridPosition, pair<int, int> prevGridPosition, pair<int, int> prevOfPrevGridPosition) {
	int result = 0;
	int up, down, left, right;

	if (gridPosition.first < 0 || gridPosition.first > height - 1 || gridPosition.second < 0 || gridPosition.second > width - 1) {
		return 0;
	}
	else if (gridPosition.first == prevOfPrevGridPosition.first && gridPosition.second == prevOfPrevGridPosition.second) {
		return 0;
	}

	else if (searchDepth < 4) {
		if (searchDepth == 2) {
			if (prevGridPosition.first == gridPosition.first) {
				if (gridPosition.first > 0 && gridPosition.first < height - 1) {
					result = (paper[gridPosition.first - 1][gridPosition.second] + paper[gridPosition.first + 1][gridPosition.second]);
				}
			}
			else if (prevGridPosition.second == gridPosition.second) {
				if (gridPosition.second > 0 && gridPosition.second < width - 1) {
					result = (paper[gridPosition.first][gridPosition.second - 1] + paper[gridPosition.first][gridPosition.second + 1]);
				}
			}
		}

		up = evaluateGrid(searchDepth + 1, paper, height, width, { gridPosition.first - 1, gridPosition.second }, gridPosition, prevGridPosition);
		down = evaluateGrid(searchDepth + 1, paper, height, width, { gridPosition.first + 1, gridPosition.second }, gridPosition, prevGridPosition);
		left = evaluateGrid(searchDepth + 1, paper, height, width, { gridPosition.first, gridPosition.second - 1 }, gridPosition, prevGridPosition);
		right = evaluateGrid(searchDepth + 1, paper, height, width, { gridPosition.first, gridPosition.second + 1 }, gridPosition, prevGridPosition);

		result = max({ result, up, down, left, right });

		return (result + paper[gridPosition.first][gridPosition.second]);
	}
	else {
		return paper[gridPosition.first][gridPosition.second];
	}
}
