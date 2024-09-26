#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

void dfs(string originalDirectory, string currentDirectory, 
gp_hash_table<string, vector<pair<string, bool>>>& graph, 
gp_hash_table<string, gp_hash_table<string, int>>& info);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    gp_hash_table<string, vector<pair<string, bool>>> graph;

    for (int i=0; i<N+M; i++) {
        string P, F;
        int C;

        cin >> P >> F >> C;

        graph[P].emplace_back(F, C);
    }

    int Q;
    cin >> Q;

    gp_hash_table<string, gp_hash_table<string, int>> info;
    unordered_set<string> visited;

    for (int q=0; q<Q; q++) {
        string input;
        cin >> input;

        string directory;
        for (char c : input) {
            if (c == '/') {
                directory = "";
            }
            else {
                directory += c;
            }
        }

        if (visited.find(directory) == visited.end()) {
            dfs(directory, directory, graph, info);
            visited.insert(directory);
        }

        int total = 0;
        for (auto& [_, v] : info[directory]) {
            total += v;
        }

        cout << info[directory].size() << " " << total << '\n';
    }

    return 0;
}

void dfs(string originalDirectory, string currentDirectory, 
    gp_hash_table<string, vector<pair<string, bool>>>& graph, 
    gp_hash_table<string, gp_hash_table<string, int>>& info) {

    for (auto& [F, C] : graph[currentDirectory]) {
        if (C == 1) {
            dfs(originalDirectory, F, graph, info);
        }
        else {
            if (info[originalDirectory].find(F) == info[originalDirectory].end()) {
                info[originalDirectory][F] = 0;
            }
            info[originalDirectory][F] += 1;
        }
    }
}