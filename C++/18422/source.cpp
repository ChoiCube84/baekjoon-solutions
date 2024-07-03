#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isInRange(pll position, int N, int M);
void updateVisited(vector<vector<bool>>& visited, const vector<vector<bool>>& grid, pll position);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N, vector<bool>(M, false));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pll> q;

    for (int i=0; i<N; i++) {
        string input;
        cin >> input;

        for (int j=0; j<M; j++) {
            if (input[j] == '*') {
                grid[i][j] = true;
                q.emplace(i, j);
            }
        }
    }

    int result = 0;

    while (!q.empty()) {
        pll curr = q.front();
        q.pop();

        if (visited[curr.first][curr.second]) {
            continue;
        }
        else {
            result++;
            updateVisited(visited, grid, curr);
        }
    }

    cout << result;

    return 0;
}

bool isInRange(pll position, int N, int M) {
    if (position.first < 0 || position.first > N - 1) {
        return false;
    }
    else if (position.second < 0 || position.second > M - 1) {
        return false;
    }
    else {
        return true;
    }
}

void updateVisited(vector<vector<bool>>& visited, const vector<vector<bool>>& grid, pll position) {
    int N = visited.size();
    int M = visited[0].size();

    queue<pll> q;
    q.emplace(position);

    while (!q.empty()) {
        pll curr = q.front();
        q.pop();

        if (visited[curr.first][curr.second] == false && grid[curr.first][curr.second] == true) {
            visited[curr.first][curr.second] = true;

            for (int dir=0; dir<4; dir++) {
                pll next = curr;
                next.first += dy[dir];
                next.second += dx[dir];

                if (isInRange(next, N, M)) {
                    q.emplace(next);
                }
            }
        }
    }
}