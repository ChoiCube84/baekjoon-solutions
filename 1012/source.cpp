#include <bits/stdc++.h>

using namespace std;

int T, M, N, K, connected = 0;
int field[50][50] = { 0, };
bool visited[50][50] = { 0, };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs(void);
bool isPositionInRange(pair <int, int> position);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        connected = 0;

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                field[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;

            field[x][y] = 1;
        }

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (field[i][j] == 1 && visited[i][j] == false) {
                    q.push({ i, j });
                    visited[i][j] = true;
                    bfs();
                    connected++;
                }
            }
        }

        cout << connected << "\n";
    }

    return 0;
}

void bfs(void) {
    while (!q.empty()) {
        pair<int, int> currentPosition = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> positionToVisit = { currentPosition.first + dx[i], currentPosition.second + dy[i] };

            if (isPositionInRange(positionToVisit) && field[positionToVisit.first][positionToVisit.second] == 1 && visited[positionToVisit.first][positionToVisit.second] == false) {
                q.push(positionToVisit);
                visited[positionToVisit.first][positionToVisit.second] = true;
            }
        }

    }
}

bool isPositionInRange(pair <int, int> position) {
    if (position.first < 0 || position.first > M - 1) {
        return false;
    }
    else if (position.second < 0 || position.second > N - 1) {
        return false;
    }
    else {
        return true;
    }
}