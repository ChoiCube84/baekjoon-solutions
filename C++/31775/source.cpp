#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;
using ld = long double;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    
    bool foundL = S1[0] == 'l' || S2[0] == 'l' || S3[0] == 'l';
    bool foundK = S1[0] == 'k' || S2[0] == 'k' || S3[0] == 'k';
    bool foundP = S1[0] == 'p' || S2[0] == 'p' || S3[0] == 'p';
    
    if (foundL && foundK && foundP) {
        cout << "GLOBAL";
    }
    else {
        cout << "PONIX";
    }
    
    return 0;
}
