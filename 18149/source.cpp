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

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int n;
        cin >> n;

        std::priority_queue<int, vector<int>, greater<>> pq;

        for (int i=0; i<n; i++) {
            int size;
            cin >> size;

            pq.push(size);
        }

        int result = 0;
        
        int lightest = pq.top();
        pq.pop();
        
        while (!pq.empty()) {
            lightest += pq.top();
            pq.pop();

            result += lightest;
            pq.push(lightest);
            
            lightest = pq.top();
            pq.pop();
        }

        cout << result << "\n";
    }
    
    return 0;
}