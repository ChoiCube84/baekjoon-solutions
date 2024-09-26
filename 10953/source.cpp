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

    string T;
    cin >> T;

    for (int i=0; i<stoi(T); i++) {
        string input;
        cin >> input;

        cout << static_cast<int>((input[0] - '0') + (input[2] - '0')) << '\n';
    }
    
    return 0;
}