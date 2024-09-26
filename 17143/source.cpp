#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

struct Shark {
    int row;
    int col;
    int dr;
    int dc;
    int size;

    Shark() : row(0), col(0), dr(0), dc(0), size(0) {}

    Shark(int r, int c, int s, int d, int z) : row(r), col(c), size(z) {
        switch (d) {
            case 1:
                dr = -s;
                dc = 0;
                break;
            case 2:
                dr = s;
                dc = 0;
                break;
            case 3:
                dr = 0;
                dc = s;
                break;
            case 4:
                dr = 0;
                dc = -s;
                break;
            default:
                break;
        }
    }

    void move(int R, int C) {
        row -= 1;
        col -= 1;

        row = (row + dr) % (2 * (R - 1));
        col = (col + dc) % (2 * (C - 1));

        if (row < 0) {
            row += 2 * (R - 1);
        }

        if (col < 0) {
            col += 2 * (C - 1);
        }

        if (row >= R) {
            dr = -dr;
            row = 2 * (R - 1) - row;
        }

        if (col >= C) {
            dc = -dc;
            col = 2 * (C - 1) - col;
        }

        row += 1;
        col += 1;
    }

    void clear() {
        row = 0;
        col = 0;
        dr = 0;
        dc = 0;
        size = 0;
    }
};

void printGrid(const vector<vector<Shark>>& ocean, int R, int C);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C, M;
    cin >> R >> C >> M;

    queue<Shark> sharks;
    vector<vector<Shark>> ocean(R+1, vector<Shark>(C+1, Shark()));

    for (int i=0; i<M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        Shark shark(r, c, s, d, z);

        sharks.push(shark);
        ocean[r][c] = shark;
    }

    int result = 0;
    for (int hunt=1; hunt<=C; hunt++) {
        for (int r=1; r<=R; r++) {
            if (ocean[r][hunt].size > 0) {
                result += ocean[r][hunt].size;
                ocean[r][hunt].clear();
                break;
            }
        }

        queue<Shark> newSharks;
        queue<pair<int, int>> check;

        while (!sharks.empty()) {
            Shark curr = sharks.front();
            sharks.pop();

            if (ocean[curr.row][curr.col].size > 0) {
                ocean[curr.row][curr.col].clear();
                curr.move(R, C);
                newSharks.push(curr);
            }
        }

        while (!newSharks.empty()) {
            Shark curr = newSharks.front();
            newSharks.pop();

            if (ocean[curr.row][curr.col].size == 0) {
                check.emplace(curr.row, curr.col);
            }
            if (ocean[curr.row][curr.col].size < curr.size) {
                ocean[curr.row][curr.col] = curr;
            }
        }

        while (!check.empty()) {
            pair<int, int> curr = check.front();
            check.pop();

            sharks.push(ocean[curr.first][curr.second]);
        }
    }

    cout << result;

    return 0;
}

void printGrid(const vector<vector<Shark>>& ocean, int R, int C) {
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            cout << ocean[r][c].size << " ";
        }
        cout << "\n";
    }
}
