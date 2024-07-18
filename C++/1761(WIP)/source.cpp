#include <bits/extc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

vector<vector<pll>> tree(40001);

vector<int> depth(40001, 0);
vector<vector<pll>> parent(40001, vector<pll>(17));
vector<bool> visited(40001, false);

void setImmediateParent(int currentNode, int currentDepth);
void setParentSparseTable(int N);
int findDistance(int nodeA, int nodeB);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, nodeA, nodeB, weight;

    cin >> N;

    for (int i=0; i<N-1; i++) {
        cin >> nodeA >> nodeB >> weight;

        tree[nodeA].emplace_back(nodeB, weight);
        tree[nodeB].emplace_back(nodeA, weight);
    }

    setImmediateParent(1, 0);
    setParentSparseTable(N);

    cin >> M;

    for (int i=0; i<M; i++) {
        cin >> nodeA >> nodeB;
        cout << findDistance(nodeA, nodeB) << '\n';
    }

    return 0;
}

void setImmediateParent(int curr, int currentDepth) {
    visited[curr] = true;
    depth[curr] = currentDepth;

    for (auto [next, dist] : tree[curr]) {
        if (visited[next] == false) {
            parent[next][0].first = curr;
            parent[next][0].second = dist;

            setImmediateParent(next, currentDepth + 1);
        }
    }
}

void setParentSparseTable(int N) {
    int maximumHeight = 0;

    for (int tempN=N; tempN>1; maximumHeight++) {
        tempN >>= 1;
    }

    for (int i=1; i<=maximumHeight; i++) {
        for (int j=1; j<=N; j++) {
            parent[j][i].first = parent[parent[j][i-1].first][i-1].first;
            parent[j][i].second = parent[j][i-1].second + parent[parent[j][i-1].first][i-1].second;
        }
    }
}

int findDistance(int nodeA, int nodeB) {
    if (depth[nodeA] < depth[nodeB]) {
        swap(nodeA, nodeB);
    }

    int distFromNodeA = 0;
    int distFromNodeB = 0;

    int difference = depth[nodeA] - depth[nodeB];
    int power = 0;

    while (difference > 0) {
        if (difference % 2 == 1) {
            distFromNodeA += parent[nodeA][power].second;
            nodeA = parent[nodeA][power].first;
        }
        difference >>= 1;
        power++;
    }

    if (nodeA == nodeB) {
        return distFromNodeA;
    }
    else {
        for (int i=16; i>=0; i--) {
            if (parent[nodeA][i].first != 0 && parent[nodeA][i].first != parent[nodeB][i].first) {
                distFromNodeA += parent[nodeA][i].second;
                distFromNodeB += parent[nodeB][i].second;

                nodeA = parent[nodeA][i].first;
                nodeB = parent[nodeB][i].first;
            }
            else {
                for (int j=0; j<=i; j++) {
                    if (parent[nodeA][j].first == parent[nodeB][j].first) {
                        distFromNodeA += parent[nodeA][j].second;
                        distFromNodeB += parent[nodeB][j].second;
                        break;
                    }
                }
                break;
            }
        }

        return distFromNodeA + distFromNodeB;
    }
}