#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    tree<int, less<int>, rb_tree_tag, tree_order_statistics_node_update> pq;

    for (int i=1; i<=N; i++) {
        int curr;
        cin >> curr;

        pq.insert(make_pair(curr, curr));
        cout << pq.find_by_order((i+1)/2)->first << '\n';
    }
    
    return 0;
}