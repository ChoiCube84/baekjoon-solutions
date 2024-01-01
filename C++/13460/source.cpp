#include <bits/stdc++.h>

#define EMPTY 0
#define WALL 1
#define GOAL 2
#define RED 3
#define BLUE 4

#define FAIL 0
#define SUCCESS 1
#define CONTINUE 2

using namespace std;

using Grid = array<array<int, 10>, 10>;

int N, M;
Grid board;

int escapeLength(void);

int left_tilt(Grid& curr);
int right_tilt(Grid& curr);
int up_tilt(Grid& curr);
int down_tilt(Grid& curr);

pair<pair<int, int>, pair<int, int>> findRB(Grid& curr);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        
        for (int j=0; j<M; j++) {
            switch (temp[j]) {
                case '.':
                    board[i][j] = EMPTY;
                    break;
                case '#':
                    board[i][j] = WALL;
                    break;
                case 'O':
                    board[i][j] = GOAL;
                    break;
                case 'R':
                    board[i][j] = RED;
                    break;
                case 'B':
                    board[i][j] = BLUE;
                    break;
            } 
        }
    }

    int result = escapeLength();
    if (result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << escapeLength();
    }

    return 0;
}

int escapeLength(void) {
    int minimum = INT_MAX;

    queue<pair<Grid, int>> q;
    q.emplace(board, 0);

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.second >= 10 || minimum <= curr.second) {
            continue;
        }

        for (int i=0; i<4; i++) {
            Grid next = curr.first;
            int result;

            switch (i) {
                case 0:
                    result = left_tilt(next);
                    break;
                case 1:
                    result = right_tilt(next);
                    break;
                case 2:
                    result = up_tilt(next);
                    break;
                case 3:
                    result = down_tilt(next);
                    break;
            }

            switch (result) {
                case FAIL:
                    break;
                case SUCCESS:
                    minimum = min(minimum, curr.second + 1);
                    break;
                case CONTINUE:
                    q.emplace(next, curr.second + 1);
                    break;
            }
        }
    }

    return minimum;
}

int left_tilt(Grid& curr) {
    auto marbles = findRB(curr);
    auto red = marbles.first;
    auto blue = marbles.second;

    int newRed, newBlue;
    bool redIn = false;
    bool blueIn = false;

    if (red.second < blue.second) {
        for (newRed=red.second; curr[red.first][newRed - 1] == EMPTY; newRed--);
        if (curr[red.first][newRed - 1] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[red.first][newRed] = RED;
        }

        for (newBlue=blue.second; curr[blue.first][newBlue - 1] == EMPTY; newBlue--);
        if (curr[blue.first][newBlue - 1] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[blue.first][newBlue] = BLUE;
        }
    }
    else {
        for (newBlue=blue.second; curr[blue.first][newBlue - 1] == EMPTY; newBlue--);
        if (curr[blue.first][newBlue - 1] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[blue.first][newBlue] = BLUE;
        }

        for (newRed=red.second; curr[red.first][newRed - 1] == EMPTY; newRed--);
        if (curr[red.first][newRed - 1] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[red.first][newRed] = RED;
        }
    }

    if (blueIn) {
        return FAIL;
    }
    else if (redIn) {
        return SUCCESS;
    }
    else {
        return CONTINUE;
    }
}

int right_tilt(Grid& curr) {
    auto marbles = findRB(curr);
    auto red = marbles.first;
    auto blue = marbles.second;

    int newRed, newBlue;
    bool redIn = false;
    bool blueIn = false;

    if (red.second > blue.second) {
        for (newRed=red.second; curr[red.first][newRed + 1] == EMPTY; newRed++);
        if (curr[red.first][newRed + 1] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[red.first][newRed] = RED;
        }

        for (newBlue=blue.second; curr[blue.first][newBlue + 1] == EMPTY; newBlue++);
        if (curr[blue.first][newBlue + 1] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[blue.first][newBlue] = BLUE;
        }
    }
    else {
        for (newBlue=blue.second; curr[blue.first][newBlue + 1] == EMPTY; newBlue++);
        if (curr[blue.first][newBlue + 1] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[blue.first][newBlue] = BLUE;
        }

        for (newRed=red.second; curr[red.first][newRed + 1] == EMPTY; newRed++);
        if (curr[red.first][newRed + 1] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[red.first][newRed] = RED;
        }
    }

    if (blueIn) {
        return FAIL;
    }
    else if (redIn) {
        return SUCCESS;
    }
    else {
        return CONTINUE;
    }
}

int up_tilt(Grid& curr) {
    auto marbles = findRB(curr);
    auto red = marbles.first;
    auto blue = marbles.second;

    int newRed, newBlue;
    bool redIn = false;
    bool blueIn = false;

    if (red.first < blue.first) {
        for (newRed=red.first; curr[newRed - 1][red.second] == EMPTY; newRed--);
        if (curr[newRed - 1][red.second] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[newRed][red.second] = RED;
        }

        for (newBlue=blue.first; curr[newBlue - 1][blue.second] == EMPTY; newBlue--);
        if (curr[newBlue - 1][blue.second] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[newBlue][blue.second] = BLUE;
        }
    }
    else {
        for (newBlue=blue.first; curr[newBlue - 1][blue.second] == EMPTY; newBlue--);
        if (curr[newBlue - 1][blue.second] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[newBlue][blue.second] = BLUE;
        }

        for (newRed=red.first; curr[newRed - 1][red.second] == EMPTY; newRed--);
        if (curr[newRed - 1][red.second] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[newRed][red.second] = RED;
        }
    }

    if (blueIn) {
        return FAIL;
    }
    else if (redIn) {
        return SUCCESS;
    }
    else {
        return CONTINUE;
    }
}

int down_tilt(Grid& curr) {
    auto marbles = findRB(curr);
    auto red = marbles.first;
    auto blue = marbles.second;

    int newRed, newBlue;
    bool redIn = false;
    bool blueIn = false;

    if (red.first > blue.first) {
        for (newRed=red.first; curr[newRed + 1][red.second] == EMPTY; newRed++);
        if (curr[newRed + 1][red.second] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[newRed][red.second] = RED;
        }

        for (newBlue=blue.first; curr[newBlue + 1][blue.second] == EMPTY; newBlue++);
        if (curr[newBlue + 1][blue.second] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[newBlue][blue.second] = BLUE;
        }
    }
    else {
        for (newBlue=blue.first; curr[newBlue + 1][blue.second] == EMPTY; newBlue++);
        if (curr[newBlue + 1][blue.second] == GOAL) {
            blueIn = true;
        }
        curr[blue.first][blue.second] = EMPTY;
        if (!blueIn) {
            curr[newBlue][blue.second] = BLUE;
        }

        for (newRed=red.first; curr[newRed + 1][red.second] == EMPTY; newRed++);
        if (curr[newRed + 1][red.second] == GOAL) {
            redIn = true;
        }
        curr[red.first][red.second] = EMPTY;
        if (!redIn) {
            curr[newRed][red.second] = RED;
        }
    }

    if (blueIn) {
        return FAIL;
    }
    else if (redIn) {
        return SUCCESS;
    }
    else {
        return CONTINUE;
    }
}

pair<pair<int, int>, pair<int, int>> findRB(Grid& curr) {
    pair<int, int> red, blue;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (curr[i][j] == RED) {
                red = make_pair(i, j);
            }
            else if (curr[i][j] == BLUE) {
                blue = make_pair(i, j);
            }
        }
    }

    return make_pair(red, blue);
}
