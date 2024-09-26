#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int simulate(pii a, pii b, vector<pii> towns);
bool isInRange(pii point);

int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int result = INT_MAX;
    cin >> N >> M;
   
    vector<vector<bool>> grid(N, vector<bool>(M, false));
   
    vector<pii> spaces;
    vector<pii> towns;
   
    for (int i=0; i<N; i++) {
        string input;
        cin >> input;
       
        for (int j=0; j<M; j++) {
            if (input[j] == '1') {
                grid[i][j] = true;
                towns.emplace_back(i, j);
            }
            else {
                spaces.emplace_back(i, j);
            }
        }
    }
   
    for (int a=0; a<spaces.size() - 1; a++) {
        for (int b=a+1; b<spaces.size(); b++) {
            result = min(simulate(spaces[a], spaces[b], towns), result);
        }
    }
   
    cout << result;
   
    return 0;
}

int simulate(pii a, pii b, vector<pii> towns) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<pii, int>> q;
   
    visited[a.first][a.second] = true;
    visited[b.first][b.second] = true;
   
    q.push(make_pair(a, 0));
    q.push(make_pair(b, 0));
   
    while (true) {
        auto curr = q.front();
        q.pop();
       
        for (int dir=0; dir<4; dir++) {
            pii newPoint = curr.first;
           
            newPoint.first += dy[dir];
            newPoint.second += dx[dir];
           
            if (isInRange(newPoint) && !visited[newPoint.first][newPoint.second]) {
                visited[newPoint.first][newPoint.second] = true;
                q.push(make_pair(newPoint, curr.second + 1));
            }
        }
       
        bool ended = true;
        vector<pii> visitedTowns;
       
        for (int i=0; i<towns.size(); i++) {
            if (!visited[towns[i].first][towns[i].second]) {
                ended = false;
                break;
            }
            else {
                visitedTowns.emplace_back(towns[i]);
            }
        }
       
        if (ended) {
            return curr.second + 1;
        }
        else {
            for (auto town : visitedTowns) {
                towns.erase(remove(towns.begin(), towns.end(), town), towns.end());
            }
        }
    }
}

bool isInRange(pii point) {
    if (point.first < 0 || point.first > N-1) {
        return false;
    }
    else if (point.second < 0 || point.second > M-1) {
        return false;
    }
    else {
        return true;
    }
}
