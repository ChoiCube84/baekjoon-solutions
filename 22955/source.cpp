#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct pll_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pll x) const {
        static const uint64_t random = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first) ^ (splitmix64(x.second) << 3) ^ splitmix64(random);
    }
};

struct cmp {
    bool operator()(const pair<pll, int>& A, const pair<pll, int>& B) const {
        return A.second > B.second;
    }
};

bool isInRange(pll pos, int N, int M);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> roomInfo(N, vector<char>(M));
    gp_hash_table<pll, int, pll_hash> table;
    pll initialPosition, escape;

    for (int i=0; i<N; i++) {
        string input;
        cin >> input;

        for (int j=0; j<M; j++) {
            roomInfo[i][j] = input[j];

            if (roomInfo[i][j] == 'C') {
                initialPosition = make_pair(i, j);
                roomInfo[i][j] = 'F';
            }
            else if (roomInfo[i][j] == 'E') {
                escape = make_pair(i, j);
            }

            table[make_pair(i, j)] = INT_MAX;
        }
    }

    gp_hash_table<pll, vector<pair<pll, int>>, pll_hash> graph;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            switch (roomInfo[i][j]) {
                case 'F':
                    if (isInRange(make_pair(i, j-1), N, M)) {
                        graph[make_pair(i, j)].emplace_back(make_pair(i, j-1), 1);
                    }
                    if (isInRange(make_pair(i, j+1), N, M)) {
                        graph[make_pair(i, j)].emplace_back(make_pair(i, j+1), 1);
                    }
                    break;
                case 'L':
                    if (isInRange(make_pair(i, j-1), N, M)) {
                        graph[make_pair(i, j)].emplace_back(make_pair(i, j-1), 1);
                    }
                    if (isInRange(make_pair(i, j+1), N, M)) {
                        graph[make_pair(i, j)].emplace_back(make_pair(i, j+1), 1);
                    }
                    if (isInRange(make_pair(i-1, j), N, M)) {
                        graph[make_pair(i, j)].emplace_back(make_pair(i-1, j), 5);
                    }
                    if (isInRange(make_pair(i-1, j), N, M) && roomInfo[i-1][j] != 'D' && roomInfo[i-1][j] != 'X') {
                        graph[make_pair(i-1, j)].emplace_back(make_pair(i, j), 5);
                    }
                    break;
                case 'X':
                    int bottom = i;
                    while (roomInfo[bottom][j] == 'X') {
                        bottom++;
                    }
                    graph[make_pair(i, j)].emplace_back(make_pair(bottom, j), 10);
                    break;
            }
        }
    }

    table[initialPosition] = 0;

    std::priority_queue<pair<pll, int>, vector<pair<pll, int>>, cmp> pq;

    pq.emplace(initialPosition, 0);

    while (!pq.empty()) {
        auto [curr, dist] = pq.top();
        pq.pop();

        if (table.find(curr) == table.end() || table[curr] < dist) {
            continue;
        }

        for (auto& [next, nextDist] : graph[curr]) {
            if (table[next] > table[curr] + nextDist) {
                table[next] = table[curr] + nextDist;
                pq.emplace(next, table[next]);
            }
        }
    }

    if (table[escape] == INT_MAX) {
        cout << "dodo sad";
    }
    else {
        cout << table[escape];
    }

    return 0;
}

bool isInRange(pll pos, int N, int M) {
    if (pos.first < 0 || pos.first > N-1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > M-1) {
        return false;
    }
    else {
        return true;
    }
}