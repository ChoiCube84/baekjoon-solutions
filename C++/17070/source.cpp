#include <bits/stdc++.h>

constexpr auto HORIZONTAL = 0;
constexpr auto VERTICAL = 1;
constexpr auto DIAGONAL = 2;

using namespace std;

int N;
vector<int> blocked[16];

int travel(int x, int y, int type);
bool checkSpace(int x, int y);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			blocked[j].resize(N);
			cin >> blocked[j][i];
		}
	}

	int result = travel(1, 0, HORIZONTAL);
	cout << result;

	return 0;
}

int travel(int x, int y, int type) {
	int result = 0;

	if (x == N - 1 && y == N - 1) {
		return 1;
	}

	switch (type) {

	case HORIZONTAL:
		if (checkSpace(x + 1, y) == true) {
			result += travel(x + 1, y, HORIZONTAL);

			if (checkSpace(x, y + 1) == true && checkSpace(x + 1, y + 1) == true) {
				result += travel(x + 1, y + 1, DIAGONAL);
			}
		}
		break;
	
	case VERTICAL:
		if (checkSpace(x, y + 1) == true) {
			result += travel(x, y + 1, VERTICAL);

			if (checkSpace(x + 1, y) == true && checkSpace(x + 1, y + 1) == true) {
				result += travel(x + 1, y + 1, DIAGONAL);
			}
		}
		break;
	
	case DIAGONAL:
		if (checkSpace(x + 1, y) == true) {
			result += travel(x + 1, y, HORIZONTAL);
		}
		if (checkSpace(x, y + 1) == true) {
			result += travel(x, y + 1, VERTICAL);
		}
		if (checkSpace(x + 1, y) == true && checkSpace(x, y + 1) == true && checkSpace(x + 1, y + 1) == true) {
			result += travel(x + 1, y + 1, DIAGONAL);
		}
		break;

	default:
		break;
	}

	return result;
}

bool checkSpace(int x, int y) {
	if (x < 0 || x > N - 1) {
		return false;
	}
	else if (y < 0 || y > N - 1) {
		return false;
	}
	else if (blocked[x][y] == 1) {
		return false;
	}
	else {
		return true;
	}
}
