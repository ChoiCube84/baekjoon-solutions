#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

const ll KING = 1;
const ll QUEEN = 2;
const ll BISHOP = 3;
const ll KNIGHT = 4;
const ll ROOK = 5;
const ll PAWN_WHITE = 6;
const ll PAWN_BLACK = 7;

ll k_dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll k_dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

ll n_dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
ll n_dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve(const string& FEN);
bool IsInRange(ll x, ll y);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string FEN;
	
	while (cin >> FEN) {
		solve(FEN);
	}
	
	return 0;
}

void solve(const string& FEN) {
	array<array<ll, 8>, 8> board;
	array<array<ll, 8>, 8> visited;
	
	char delim = '/';
	
	for (ll i=0; i<8; i++) {
		for (ll j=0; j<8; j++) {
			board[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	
	stringstream ss(FEN);
	string curr;
	
	ll row = 0;
	while (getline(ss, curr, delim)) {
		ll ptr = 0;
		for (ll col=0; col<8; col++) {
			char c = curr[ptr++];
			switch (c) {
				case 'k':
				case 'K':
					board[row][col] = KING;
					visited[row][col] = 1;
					break;
				case 'q':
				case 'Q':
					board[row][col] = QUEEN;
					visited[row][col] = 1;					
					break;
				case 'b':
				case 'B':
					board[row][col] = BISHOP;
					visited[row][col] = 1;
					break;
				case 'n':
				case 'N':
					board[row][col] = KNIGHT;
					visited[row][col] = 1;
					break;
				case 'r':
				case 'R':
					board[row][col] = ROOK;
					visited[row][col] = 1;
					break;
				case 'p':
					board[row][col] = PAWN_BLACK;
					visited[row][col] = 1;
					break;
				case 'P':
					board[row][col] = PAWN_WHITE;
					visited[row][col] = 1;
					break;
				default:
					col += (static_cast<ll>(c) - '1');
					break;
			}
		}
		row++;
	}
	
	for (ll row=0; row<8; row++) {
		for (ll col=0; col<8; col++) {
			switch (board[row][col]) {
				case KING:
					for (ll dir=0; dir<8; dir++) {
						ll y = row + k_dy[dir];
						ll x = col + k_dx[dir];
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
					}
					break;
				case QUEEN:
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					break;
				case BISHOP:
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					break;
				case KNIGHT:
					for (ll dir=0; dir<8; dir++) {
						ll y = row + n_dy[dir];
						ll x = col + n_dx[dir];
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
					}
					break;
				case ROOK:
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row + diff;
						ll x = col;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row - diff;
						ll x = col;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row;
						ll x = col + diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					
					for (ll diff = 1; diff < 8; diff++) {
						ll y = row;
						ll x = col - diff;
						
						if (IsInRange(x, y) && board[y][x] == 0) {
							visited[y][x] = 1;
						}
						else {
							break;
						}
					}
					break;
				case PAWN_WHITE:
					if (IsInRange(col - 1, row - 1) && visited[row - 1][col - 1] == 0) {
						visited[row - 1][col - 1] = 1;
					}
					
					if (IsInRange(col + 1, row - 1) && visited[row - 1][col + 1] == 0) {
						visited[row - 1][col + 1] = 1;
					}
					break;
				case PAWN_BLACK:
					if (IsInRange(col - 1, row + 1) && board[row + 1][col - 1] == 0) {
						visited[row + 1][col - 1] = 1;
					}
					
					if (IsInRange(col + 1, row + 1) && board[row + 1][col + 1] == 0) {
						visited[row + 1][col + 1] = 1;
					}
					break;
			}
		}
	}
	
	ll result = 0;
	
	for (ll i=0; i<8; i++) {
		for (ll j=0; j<8; j++) {
			if (visited[i][j] == 0) {
				result++;
			}
		}
	}
	
	cout << result << '\n';
}

bool IsInRange(ll x, ll y) {
	if (x < 0 || x > 7) {
		return false;
	}
	else if (y < 0 || y > 7) {
		return false;
	}
	else {
		return true;
	}
}