#include <bits/stdc++.h>

using namespace std;

int N, M;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<vector<bool>> visited;

vector<vector<int>> grid;
vector<vector<int>> exposed;

queue<pair<int, int>> q;
queue<pair<int, int>> airQ;

void borderAirFilling(void);
void fillAir(void);
void oneStepExposure(void);
void meltCheese(void);

bool isInRange(const pair<int, int>& position);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	grid.resize(N);
	exposed.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++) {
		grid[i].resize(M);
		exposed[i].resize(M);
		visited[i].resize(M);

		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	int answer = 0;

	borderAirFilling();
	while (!q.empty()) {
		fillAir();
		oneStepExposure();
		meltCheese();

		answer++;
	}

	cout << answer;

	return 0;
}

void borderAirFilling(void) {
	for (int i = 0; i < N; i++) {
		grid[i][0] = grid[i][M - 1] = 2;

		airQ.push(make_pair(i, 0));
		airQ.push(make_pair(i, M - 1));
	}

	for (int i = 0; i < M; i++) {
		grid[0][i] = grid[N - 1][i] = 2;

		airQ.push(make_pair(0, i));
		airQ.push(make_pair(N - 1, i));
	}
}

void fillAir(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			if (grid[i][j] == 2) {
				airQ.push(make_pair(i, j));
			}
		}
	}
	
	while (!airQ.empty()) {
		pair<int, int> currentPosition = airQ.front();
		airQ.pop();

		if (visited[currentPosition.first][currentPosition.second] == false) {
			visited[currentPosition.first][currentPosition.second] = true;

			for (int i = 0; i < 4; i++) {
				int newY = currentPosition.first + dy[i];
				int newX = currentPosition.second + dx[i];

				pair<int, int> newPosition = make_pair(newY, newX);

				if (isInRange(newPosition) && visited[newY][newX] == false && grid[newY][newX] == 0) {
					grid[newY][newX] = 2;
					airQ.push(newPosition);
				}
			}
		}
	}
}

void oneStepExposure(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			exposed[i][j] = 0;
		}
	}
	
	size_t qSize = q.size();
	for (size_t i = 0; i < qSize; i++) {
		pair<int, int> currentPosition = q.front();
		q.pop();

		for (int j = 0; j < 4; j++) {
			int newY = currentPosition.first + dy[j];
			int newX = currentPosition.second + dx[j];

			pair<int, int> newPosition = make_pair(newY, newX);
			
			if (isInRange(newPosition) && grid[newY][newX] == 2) {
				exposed[currentPosition.first][currentPosition.second]++;
			}
		}

		q.push(currentPosition);
	}
}

void meltCheese(void) {
	size_t size = q.size();
	for (size_t i = 0; i < size; i++) {
		pair<int, int> currentPosition = q.front();
		q.pop();

		if (exposed[currentPosition.first][currentPosition.second] > 1) {
			grid[currentPosition.first][currentPosition.second] = 0;
		}
		else {
			q.push(currentPosition);
		}
	}
}

bool isInRange(const pair<int, int>& position) {
	int y = position.first;
	int x = position.second;

	if (y < 0 || y > N - 1) {
		return false;
	}
	else if (x < 0 || x > M - 1) {
		return false;
	}
	else {
		return true;
	}
}
