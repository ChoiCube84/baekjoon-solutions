#include <bits/stdc++.h>

using namespace std;

class Board {
private:
    int N;
    vector<vector<int>> grid;

    void flipHorizontal();
    void transpose();
public:
    Board();

    int searchMax(int depth);

    void swipeLeft();
    void swipeRight();
    void swipeUp();
    void swipeDown();

    int maxBlock();

    void printGrid();
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Board board;

    cout << board.searchMax(5);

    return 0;
}

Board::Board() {
    cin >> N;
    grid.resize(N, vector<int>(N, 0));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> grid[i][j];
        }
    }
}

void Board::flipHorizontal() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<(N/2); j++) {
            swap(grid[i][j], grid[i][N - 1 - j]);
        }
    }
}

void Board::transpose() {
    for (int i=0; i<(N-1); i++) {
        for (int j=i+1; j<N; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }
}

int Board::searchMax(int depth) {
    Board left = *this;
    Board right = *this;
    Board up = *this;
    Board down = *this;

    left.swipeLeft();
    right.swipeRight();
    up.swipeUp();
    down.swipeDown();

    if (depth > 1) {
        return max({left.searchMax(depth - 1), right.searchMax(depth - 1), up.searchMax(depth - 1), down.searchMax(depth - 1)});
    }
    else {
        return max({left.maxBlock(), right.maxBlock(), up.maxBlock(), down.maxBlock()});
    }
}

void Board::swipeLeft() {
    for (int i=0; i<N; i++) {
        vector<int> newRow;
        bool merged = false;

        for (int j=0; j<N; j++) {
            int curr = grid[i][j];
            if (curr == 0) {
                continue;
            }

            if (merged) {
                merged = false;
                newRow.emplace_back(curr);
            }
            else if (!newRow.empty() && newRow.back() == curr) {
                merged = true;
                newRow.back() += curr;
            }
            else {
                newRow.emplace_back(curr);
            }
        }

        int paddingCount = N - newRow.size();
        for (int j=0; j<paddingCount; j++) {
            newRow.emplace_back(0);
        }

        grid[i] = newRow;
    }
}

void Board::swipeRight() {
    flipHorizontal();
    swipeLeft();
    flipHorizontal();
}

void Board::swipeUp() {
    transpose();
    swipeLeft();
    transpose();
}

void Board::swipeDown() {
    transpose();
    swipeRight();
    transpose();
}

int Board::maxBlock() {
    int result = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            result = max(result, grid[i][j]);
        }
    }

    return result;
}

void Board::printGrid() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
