#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

ll dy[4] = {-1, 1, 0, 0};
ll dx[4] = {0, 0, -1, 1};

void bfs(vector<vector<bool>>& grid, ll i, ll j, ll N, ll M);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N, M;
	cin >> N >> M;
	
	vector<vector<bool>> grid(N, vector<bool>(M, false));
	vector<pll> empty_spaces;
	
	for (ll i=0; i<N; i++) {
		for (ll j=0; j<M; j++) {
			ll temp;
			cin >> temp;
			
			grid[i][j] = temp;
			
			if (grid[i][j] == false) {
				empty_spaces.emplace_back(make_pair(i, j));
			}
		}
	}
	
	ll result = 0;
	
	for (auto [i, j] : empty_spaces) {
		if (grid[i][j] == false) {
			bfs(grid, i, j, N, M);
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}

void bfs(vector<vector<bool>>& grid, ll i, ll j, ll N, ll M) {
	queue<pll> q;
    
	q.emplace(i, j);
	grid[i][j] = true;
    
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		
		for (ll dir=0; dir<4; dir++) {
			pll next;	
			
			next.first = (curr.first + dy[dir] + N) % N;
			next.second = (curr.second + dx[dir] + M) % M;
			
			if (grid[next.first][next.second] == false) {
				q.push(next);
                grid[next.first][next.second] = true;
			}
		}
	}
}