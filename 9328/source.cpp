#include <bits/stdc++.h>

using namespace std;

enum state {
    EMPTY = 0,
    // DOOR = 1 ~ 26
    WALL = 100,
    // KEY = 101 ~ 126
    DOC = 200
};

void simulate(void);

class Grid {
private:
    int height;
    int width;
    vector<vector<int>> grid;
    vector<pair<int, int>> entries;
    vector<pair<bool, vector<pair<int, int>>>> doors;
    int docCount;
    int maxDocCount;
public:
    Grid();
    void openDoors(int doorNum);
    bool checkBorder(pair<int, int> pos) const;

    bool update(pair<int, int> &lastPos);
    bool isInRange(pair<int, int> pos) const;

    int getDocCount() const;

    void printGrid();
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        simulate();
    }

    return 0;
}

void simulate(void) {
    Grid grid;
    pair<int, int> lastPos = make_pair(-1, -1);

    while (grid.update(lastPos)) {
        // grid.printGrid();
    }
    cout << grid.getDocCount() << "\n";
}

Grid::Grid() {
    docCount = 0;
    maxDocCount = 0;
    
    cin >> height >> width;

    grid.resize(height);
    doors.resize(26);

    for (int i=0; i < height; i++) {
        string row;
        cin >> row;

        grid[i].resize(width);
        for (int j=0; j < width; j++) {
            char c = row[j];

            if (checkBorder(make_pair(i, j)) && grid[i][j] == EMPTY) {
                entries.emplace_back(i, j);
            }

            switch(c) {
                case '.':
                    grid[i][j] = EMPTY;
                    break;
                case '*':
                    grid[i][j] = WALL;
                    break;
                case '$':
                    grid[i][j] = DOC;
                    maxDocCount++;
                    break;
                default:
                    if (c > 'Z') {
                        if (checkBorder(make_pair(i, j))) {
                            grid[i][j] = EMPTY;
                            doors[c - 'a'].first = true;
                        }
                        else {
                            grid[i][j] = 100 + (c - 'a' + 1);
                        }
                    }
                    else {
                        if (doors[c - 'A'].first) {
                            grid[i][j] = EMPTY;
                        }
                        else {
                            grid[i][j] = c - 'A' + 1;
                            doors[c - 'A'].second.emplace_back(i, j);
                        }
                    }
                    break;
            }
        }
    }

    string initialKeys;
    cin >> initialKeys;

    if (initialKeys != "0") {
        for (auto& key : initialKeys) {
            openDoors(key - 'a');
        }
    }
}

void Grid::openDoors(int doorNum) {
    doors[doorNum].first = true;
    for (auto& door : doors[doorNum].second) {
        grid[door.first][door.second] = EMPTY;
    }
}

bool Grid::checkBorder(pair<int, int> pos) const {
    return !((pos.first % (height - 1)) * (pos.second % (width - 1)));
}

bool Grid::update(pair<int, int> &lastPos) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<pair<int, int>> q;

    if (isInRange(lastPos)) {
        q.push(lastPos);
        visited[lastPos.first][lastPos.second] = true;
    }

    for (auto entry : entries) {
        int currInfo = grid[entry.first][entry.second];

        switch (currInfo) {
            case EMPTY:
                q.push(entry);
                visited[entry.first][entry.second] = true;
                break;
            case WALL:
                break;
            case DOC:
                docCount++;
                grid[entry.first][entry.second] = EMPTY;
                if (docCount < maxDocCount) {
                    return true;
                }
                else {
                    return false;
                }
            default:
                break;
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            auto next = make_pair(curr.first + dx[i], curr.second + dy[i]);
            if (isInRange(next) && !visited[next.first][next.second]) {
                int nextInfo = grid[next.first][next.second];
                switch (nextInfo) {
                    case EMPTY:
                        q.push(next);
                        visited[next.first][next.second] = true;
                        break;
                    case WALL:
                        continue;
                    case DOC:
                        docCount++;
                        grid[next.first][next.second] = EMPTY;
                        lastPos = next;
                        return true;
                    default:
                        if (nextInfo > 100) {
                            openDoors(nextInfo - 101);
                            grid[next.first][next.second] = EMPTY;
                            lastPos = next;
                            return true;
                        }
                        break;
                }
            }
        }
    }

    return false;
}

bool Grid::isInRange(pair<int, int> pos) const {
    if (pos.first < 0 || pos.first > height - 1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > width - 1) {
        return false;
    }
    else {
        return true;
    }
}

int Grid::getDocCount() const {
    return docCount;
}

void Grid::printGrid() {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int currInfo = grid[i][j];

            switch (currInfo) {
                case EMPTY:
                    cout << ".";
                    break;
                case WALL:
                    cout << "*";
                    break;
                case DOC:
                    cout << "$";
                    break;
                default:
                    if (currInfo > 100) {
                        cout << static_cast<char>(currInfo - 101 + 'a');
                    }
                    else {
                        cout << static_cast<char>(currInfo - 1 + 'A');
                    }
                    break;
            }
        }
        cout << "\n";
    }
}
