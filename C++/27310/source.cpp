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

    string name;
    cin >> name;

    int result = name.length();

    for (char c : name) {
        if (c == ':') {
            result++;
        }
        else if (c == '_') {
            result += 5;
        }
    }

    cout << result;
    
    return 0;
}