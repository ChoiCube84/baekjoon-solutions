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
        int N, result = 0;
        cin >> N;

        vector<int> numbers(N);
        
        for (int i=0; i<N; i++) {
            string name;
            cin >> name >> numbers[i];
        }

        sort(numbers.begin(), numbers.end());

        for (int i=0; i<N; i++) {
            result += abs((i+1) - numbers[i]);
        }

        cout << result << '\n';
    }
    
    return 0;
}