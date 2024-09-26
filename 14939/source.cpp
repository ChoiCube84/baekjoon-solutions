#include <bits/stdc++.h>

using namespace std;

void rowClick(int row, unsigned rowInfo, int &count, vector<vector<bool>> &lights);
void click(int row, int col, vector<vector<bool>> &lights);
bool rowCheck(int row, vector<vector<bool>> &lights);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> lights(10, vector<bool>(10, false));

    for (int i=0; i<10; i++) {
        string line;
        cin >> line;

        for (int j=0; j<10; j++) {
            if (line[j] == 'O') {
                lights[i][j] = true;
            }
        }
    }

    int minimum = INT_MAX;
    for (int i=0; i<(1<<10); i++) {
        int temp = 0;

        vector<vector<bool>> newLights(10, vector<bool>(10, false));
        copy(lights.begin(), lights.end(), newLights.begin());

        rowClick(0, i, temp, newLights);

        for (int row = 1; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                if (newLights[row - 1][col]) {
                    click(row, col, newLights);
                    temp++;
                }
            }
        }

        if (rowCheck(9, newLights)) {
            minimum = min(minimum, temp);
        }
    }

    if (minimum == INT_MAX) {
        cout << -1;
    }
    else {
        cout << minimum;
    }

    return 0;
}

void rowClick(int row, unsigned rowInfo, int &count, vector<vector<bool>> &lights) {
    int col = 0;
    while (rowInfo > 0) {
        if (rowInfo % 2 == 1) {
            click(row, col, lights);
            count++;
        }

        rowInfo >>= 1;
        col++;
    }
}

void click(int row, int col, vector<vector<bool>> &lights) {
    lights[row][col] = !lights[row][col];

    if (row > 0) {
        lights[row - 1][col] = !lights[row - 1][col];
    }
    if (row < 9) {
        lights[row + 1][col] = !lights[row + 1][col];
    }
    if (col > 0) {
        lights[row][col - 1] = !lights[row][col - 1];
    }
    if (col < 9) {
        lights[row][col + 1] = !lights[row][col + 1];
    }
}

bool rowCheck(int row, vector<vector<bool>> &lights) {
    for (int col=0; col<10; col++) {
        if (lights[row][col]) {
            return false;
        }
    }
    return true;
}
