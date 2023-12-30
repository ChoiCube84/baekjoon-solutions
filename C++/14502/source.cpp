#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

int lab[8][8] = {0,};
int newLab[8][8] = {0,};

vector<pair<int, int>> initVirus;
vector<pair<int, int>> emptySpace;

void deepCopy(void);
int getSafeZoneArea(void);
bool isInRange(pair<int, int> pos);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int result = 0;

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int info;
            cin >> info;

            if (info == 0) {
                emptySpace.emplace_back(i, j);
            }
            else if (info == 2) {
                initVirus.emplace_back(i, j);
            }

            lab[i][j] = info;
        }
    }

    for (int i=0; i<emptySpace.size()-2; i++) {
        for (int j=i+1; j<emptySpace.size()-1; j++) {
            for (int k=j+1; k<emptySpace.size(); k++) {
                deepCopy();

                newLab[emptySpace[i].first][emptySpace[i].second] = 1;
                newLab[emptySpace[j].first][emptySpace[j].second] = 1;
                newLab[emptySpace[k].first][emptySpace[k].second] = 1;

                result = max(result, getSafeZoneArea());
            }
        }
    }

    cout << result;

    return 0;
}

void deepCopy(void) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            newLab[i][j] = lab[i][j];
        }
    }
}

int getSafeZoneArea(void) {
    int area = 0;
    queue<pair<int, int>> q;

    for (auto& i: initVirus) {
        q.push(i);
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            pair<int, int> newPos = make_pair(curr.first + dx[i], curr.second + dy[i]);

            if (isInRange(newPos) && newLab[newPos.first][newPos.second] == 0) {
                newLab[newPos.first][newPos.second] = 2;
                q.push(newPos);
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (newLab[i][j] == 0) {
                area++;
            }
        }
    }

    return area;
}

bool isInRange(pair<int, int> pos) {
    if (pos.first < 0 || pos.first > N - 1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > M - 1) {
        return false;
    }
    else {
        return true;
    }
}
