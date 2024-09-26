#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using pii = pair<int, int>;

struct time_based_hash {
	[[gnu::const]] static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	
	template <typename T>
    size_t operator()(const std::vector<T>& v) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = FIXED_RANDOM;

        for (const auto& elem : v) {
            hash ^= std::hash<T>{}(elem) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }

        return splitmix64(hash);
    }
};

struct cmp {
    bool operator()(const pair<vector<int>, int>& A, const pair<vector<int>, int>& B) {
        return A.second > B.second;
    }
};

vector<int> applyManipulation(const vector<int>& A, pii manipulation);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    gp_hash_table<vector<int>, int, time_based_hash> table;
    std::priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, cmp> pq;
   
    int N;
    cin >> N;
   
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
   
    int M;
    cin >> M;
   
    vector<pair<pii, int>> edges(M);
    for (int i=0; i<M; i++) {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }
   
    pq.push(make_pair(A, 0));
    table[A] = 0;
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
       
        if (table[curr.first] < curr.second) {
            continue;
        }
        
        for (auto& edge : edges) {
            vector<int> next = applyManipulation(curr.first, edge.first);
           
            if (table.find(next) == table.end() || curr.second + edge.second < table[next]) {
                table[next] = curr.second + edge.second;
                pq.push(make_pair(next, table[next]));
            }
        }
    }
   
    sort(A.begin(), A.end());
   
    if (table.find(A) == table.end()) {
        cout << -1;
    }
    else {
        cout << table[A];
    }
   
    return 0;
}

vector<int> applyManipulation(const vector<int>& A, pii manipulation) {
    vector<int> result = A;
    swap(result[manipulation.first - 1], result[manipulation.second - 1]);
   
    return result;
}
