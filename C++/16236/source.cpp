#include <bits/stdc++.h>

using namespace std;

struct SharkStatus {
    pair<int, int> pos;
    int moved = 0;
    int size = 2;
    int eaten = 0;
};

int N;

int grid[20][20] = {0,};

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

SharkStatus find_next(SharkStatus start);
bool isInRange(pair<int, int> pos);

int main(void) {
    int result = -1;
    SharkStatus current;

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int temp;
            cin >> temp;

            if (temp == 9) {
                current.pos = {j,i};
                temp = 0;
            }

            grid[j][i] = temp;
        }
    }

    while (true) {
        SharkStatus next = find_next(current);

        if (result == next.moved) {
            break;
        }
        else {
            result = next.moved;
            current = next;
        }
    }

    cout << result;

    return 0;
}

SharkStatus find_next(SharkStatus start) {
    bool visit[20][20] = {false,};

    bool fishFound = false;
    SharkStatus next, bestStatus;
    bestStatus.moved = INT_MAX;

    queue<SharkStatus> q;
    q.push(start);
    visit[start.pos.first][start.pos.second] = true;

    while (!q.empty()) {
        SharkStatus current = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int newX = current.pos.first + dx[i];
            int newY = current.pos.second + dy[i];

            if (!visit[newX][newY] && isInRange({newX, newY}) && grid[newX][newY] <= current.size) {
                if (grid[newX][newY] == 0 || current.size == grid[newX][newY]) {
                    visit[newX][newY] = true;
                    q.push({{newX, newY}, current.moved + 1, current.size, current.eaten});
                }
                else if (current.size > grid[newX][newY]) {
                    visit[newX][newY] = true;
                    fishFound = true;

                    next.pos = {newX, newY};
                    next.size = current.size;
                    next.moved = current.moved + 1;
                    next.eaten = current.eaten + 1;

                    if (next.eaten >= next.size) {
                        next.eaten = 0;
                        next.size++;
                    }

                    if (bestStatus.moved > next.moved) {
                        bestStatus = next;
                    }
                    else if (bestStatus.moved == next.moved) {
                        if (bestStatus.pos.second > next.pos.second) {
                            bestStatus = next;
                        }
                        else if (bestStatus.pos.second == next.pos.second) {
                            if (bestStatus.pos.first > next.pos.first) {
                                bestStatus = next;
                            }
                        }
                    }
                }
            }
        }
    }

    if (!fishFound) {
        bestStatus = start;
    }
    else {
        grid[bestStatus.pos.first][bestStatus.pos.second] = 0;
    }

    return bestStatus;
}

bool isInRange(pair<int, int> pos) {
    if (pos.first < 0 || pos.first > N - 1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > N - 1) {
        return false;
    }
    else {
        return true;
    }
}
