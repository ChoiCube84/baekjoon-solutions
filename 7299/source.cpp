#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

struct Pos {
    ll x;
    ll y;
    ll z;
};

ll dx[6] = {-1, 1, 0, 0, 0, 0};
ll dy[6] = {0, 0, -1, 1, 0, 0};
ll dz[6] = {0, 0, 0, 0, -1, 1};

ll bfs(ll x, ll y, ll z, const vector<vector<vector<bool>>>& grid, vector<vector<vector<bool>>>& visited);
bool isInRange(const Pos& pos);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while (t--) {
        vector<vector<vector<bool>>> grid(100, vector<vector<bool>>(100, vector<bool>(100, false)));
        vector<vector<vector<bool>>> visited(100, vector<vector<bool>>(100, vector<bool>(100, false)));
        
        ll M;
        cin >> M;
        
        while (M--) {
            ll x, y, z;
            cin >> x >> y >> z;
            
            x--;
            y--;
            z--;
            
            grid[x][y][z] = true;
        }
        
        for (ll i=0; i<100; i++) {
            for (ll j=0; j<100; j++) {
                bfs(i, j, 0, grid, visited);
                bfs(i, j, 99, grid, visited);
            }
        }
        
        for (ll j=0; j<100; j++) {
            for (ll k=0; k<100; k++) {
                bfs(0, j, k, grid, visited);
                bfs(99, j, k, grid, visited);
            }
        }
        
        for (ll i=0; i<100; i++) {
            for (ll k=0; k<100; k++) {
                bfs(i, 0, k, grid, visited);
                bfs(i, 99, k, grid, visited);
            }
        }
        
        ll count = 0;
        
        for (ll i=0; i<100; i++) {
            for (ll j=0; j<100; j++) {
                for (ll k=0; k<100; k++) {
                    count += bfs(i, j, k, grid, visited);
                }
            }
        }
        
        cout << count << '\n';
    }
    
    return 0;
}

ll bfs(ll x, ll y, ll z, const vector<vector<vector<bool>>>& grid, vector<vector<vector<bool>>>& visited) {
    if (grid[x][y][z] || visited[x][y][z]) {
        return 0;
    }
    
    queue<Pos> q;
    q.push({x, y, z});
    
    while (!q.empty()) {
        Pos curr = q.front();
        q.pop();
        
        if (visited[curr.x][curr.y][curr.z] == false) {
            visited[curr.x][curr.y][curr.z] = true;
        
            for (ll dir=0; dir<6; dir++) {
                Pos next;
                
                next.x = curr.x + dx[dir];
                next.y = curr.y + dy[dir];
                next.z = curr.z + dz[dir];
                
                if (isInRange(next) && grid[next.x][next.y][next.z] == false && visited[next.x][next.y][next.z] == false) {
                    q.push(next);
                }
            }
        }
    }
    
    return 1;
}

bool isInRange(const Pos& pos) {
    if (pos.x < 0 || pos.x > 99) {
        return false;
    }
    else if (pos.y < 0 || pos.y > 99) {
        return false;
    }
    else if (pos.z < 0 || pos.z > 99) {
        return false;
    }
    else {
        return true;
    }
}
