#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isInRange(const pii& position);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<int>> grid(5, vector<int>(5, 0));
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> grid[i][j];
        }
    }
    
    int r, c;
    cin >> r >> c;
    
    int result = -1;
    queue<pair<pii, int>> q;
    
    q.push(make_pair(make_pair(r, c), 0));
    visited[r][c] = true;
    
    while (!q.empty() && result == -1) {
        auto curr = q.front();
        q.pop();
        
        for (int dir=0; dir<4; dir++) {
            pii next = curr.first;
            next.first += dy[dir];
            next.second += dx[dir];
            
            if (isInRange(next) && (visited[next.first][next.second] == false) && (grid[next.first][next.second] != -1)) {
                if (grid[next.first][next.second] == 1) {
                    result = curr.second + 1;
                    break;
                }
                
                visited[next.first][next.second] = true;
                q.push(make_pair(next, curr.second + 1));
            }
        }
    }
    
    cout << result;
    
    return 0;
}

bool isInRange(const pii& position) {
    if (position.first < 0 || position.first > 4) {
        return false;
    }
    else if (position.second < 0 || position.second > 4) {
        return false;
    }
    else {
        return true;
    }
}
