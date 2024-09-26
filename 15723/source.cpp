#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

namespace floyd_warshall {
    template <template<typename, typename> typename Table, typename Node, typename Distance>
    Table<Node, Table<Node, Distance>> getShortestPath(const Table<Node, Table<Node, Distance>>& graph) {
        Table<Node, Table<Node, Distance>> distance = graph;

        for (auto [middle, _] : distance) {
            for (auto [start, _] : distance) {
                for (auto [end, _] : distance) {
                    if (distance[start][end] > distance[start][middle] + distance[middle][end]) {
                        distance[start][end] = distance[start][middle] + distance[middle][end];
                    }
                }
            }
        }

        return distance;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    gp_hash_table<int, gp_hash_table<int, int>> graph;

    for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
            graph[i][j] = 100;
        }
    }

    int n;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<n; i++) {
        string input;
        getline(cin, input);

        graph[input[0] - 'a'][input[5] - 'a'] = 1;
    }

    auto distance = floyd_warshall::getShortestPath<gp_hash_table, int, int>(graph);

    int m;
    cin >> m;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<m; i++) {
        string input;
        getline(cin, input);

        bool result = (distance[input[0] - 'a'][input[5] - 'a'] < 100);

        if (result) {
            cout << 'T';
        }
        else {
            cout << 'F';
        }

        cout << '\n';
    }

    return 0;
}