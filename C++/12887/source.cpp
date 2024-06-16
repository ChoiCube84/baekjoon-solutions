#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isInRange(pii position, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int M, whiteCount = 0, required = 0;
    cin >> M;
    
    vector<vector<bool>> grid(2, vector<bool>(M, false));
    vector<vector<bool>> visited(2, vector<bool>(M, false));
    
    for (int i=0; i<M; i++) {
        char c;
        cin >> c;
        
        if (c == '.') {
            grid[0][i] = true;
            whiteCount++;
        }
    }
    
    for (int i=0; i<M; i++) {
        char c;
        cin >> c;
        
        if (c == '.') {
            grid[1][i] = true;
            whiteCount++;
        }
    }
    
    queue<pair<pii, int>> q;
    
    if (grid[0][0] == true) {
        q.emplace(make_pair(0, 0), 1);
        visited[0][0] = true;
    }
    
    if (grid[1][0] == true) {
        q.emplace(make_pair(1, 0), 1);
        visited[1][0] = true;
    }
    
    while (!q.empty()) {
        bool found = false;
        
        auto curr = q.front();
        q.pop();
        
        for (int dir=0; dir<4; dir++) {
            pii next = curr.first;
            
            next.first += dy[dir];
            next.second += dx[dir];
            
            if (isInRange(next, 2, M) 
            && visited[next.first][next.second] == false 
            && grid[next.first][next.second] == true) {
                visited[next.first][next.second] = true;
                
                if (next.second == M-1) {
                    required = curr.second + 1;
                    found = true;
                    break;
                }
                else {
                    q.emplace(next, curr.second + 1);
                }
            }
        }
        
        if (found) {
            break;
        }
    }
    
    cout << whiteCount - required;
    
    return 0;
}

bool isInRange(pii position, int N, int M) {
    if (position.first < 0 || position.first > N-1) {
        return false;
    }
    else if (position.second < 0 || position.second > M-1) {
        return false;
    }
    else {
        return true;
    }
}
