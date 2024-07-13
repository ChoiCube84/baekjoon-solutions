#include <bits/extc++.h>
#include "kruskal.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int posToInt(int r, int c, int R, int C, bool isLeft);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        int R, C, rightSectionOffset;
        cin >> R >> C;

        rightSectionOffset = R * C;

        vector<vector<bool>> isLeftUp(R, vector<bool>(C));

        for (int i=0; i<R; i++) {
            string input;
            cin >> input;
            
            for (int j=0; j<C; j++) {
                if (input[j] == '/') {
                    isLeftUp[i][j] = true;
                }
                else {
                    isLeftUp[i][j] = false;
                }
            }
        }

        vector<vector<int>> wallStrength(R, vector<int>(C));

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> wallStrength[i][j];
            }
        }

        DisjointSet diset(2 * R * C);

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (isLeftUp[i][j] == true) {
                    if (i > 0) {
                        diset.merge(posToInt(i, j, true), posToInt(i-1, j, !isLeftUp[i-1][j]));
                    }
                    if (i < R - 1) {
                        diset.merge(posToInt(i, j, false), posToInt(i+1, j, isLeftUp[i+1][j]));
                    }
                    if (j > 0) {
                        diset.merge(posToInt(i, j, true), posToInt(i, j-1, false));
                    }
                    if (j < C - 1) {
                        diset.merge(posToInt(i, j, false), posToInt(i, j+1, true));
                    }
                }
                else {
                    if (i > 0) {
                        diset.merge(posToInt(i, j, false), posToInt(i-1, j, !isLeftUp[i-1][j]));
                    }
                    if (i < R - 1) {
                        diset.merge(posToInt(i, j, true), posToInt(i+1, j, isLeftUp[i+1][j]));
                    }
                    if (j > 0) {
                        diset.merge(posToInt(i, j, true), posToInt(i, j-1, false));
                    }
                    if (j < C - 1) {
                        diset.merge(posToInt(i, j, false), posToInt(i, j+1, true));
                    }
                }
            }
        }

        vector<kruskal::Edge> edges;
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                edges.emplace_back(kruskal::Edge(posToInt(i, j, true), posToInt(i, j, false), wallStrength[i][j]));
            }
        }

        vector<kruskal::Edge> MST = kruskal::kruskal(edges, 2 * R * C);

        int total = 0;
        for (auto& edge : MST) {
            total += edge.weight;
        }

        cout << "Case #" << t << ": " << total << '\n';
    }
    
    return 0;
}

int posToInt(int r, int c, int R, int C, bool isLeft) {
    int rightSectionOffset = R * C;
    return r * C + c + (!isLeft) * rightSectionOffset;
}