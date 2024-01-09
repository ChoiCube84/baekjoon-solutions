#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9, 0));

bool search(int currX, int currY);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i=0; i<9; i++) {
        string line;
        cin >> line;
        for (int j=0; j<9; j++) {
            sudoku[i][j] = line[j] - '0';
        }
    }

    search(0, 0);

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << sudoku[i][j];
        }
        if (i < 8) {
            cout << "\n";
        }
    }

    return 0;
}

bool search(int currX, int currY) {
    bool candidate[9];
    for (int i=0; i<9; i++) {
        candidate[i] = true;
    }

    int nextX = currX;
    int nextY = currY + 1;

    nextX += (nextY / 9);
    nextY %= 9;

    if (currX == 9) {
        return true;
    }

    if (sudoku[currX][currY] == 0) {
        for (int i=0; i<9; i++) {
            int value = sudoku[i][currY];

            if (value == 0) {
                continue;
            }

            candidate[value - 1] = false;
        }

        for (int j=0; j<9; j++) {
            int value = sudoku[currX][j];

            if (value == 0 || currY == j) {
                continue;
            }

            candidate[value - 1] = false;
        }

        int leftTopX = (currX / 3) * 3;
        int leftTopY = (currY / 3) * 3;

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int aroundX = leftTopX + i;
                int aroundY = leftTopY + j;

                int value = sudoku[aroundX][aroundY];

                if (currX == aroundX && currY == aroundY) {
                    continue;
                }

                candidate[value - 1] = false;
            }
        }
    }
    else {
        return search(nextX, nextY);
    }

    for (int i=0; i<9; i++) {
        if (candidate[i]) {
            sudoku[currX][currY] = i + 1;

            if (search(nextX, nextY)) {
                return true;
            }
        }
    }

    sudoku[currX][currY] = 0;
    return false;
}
