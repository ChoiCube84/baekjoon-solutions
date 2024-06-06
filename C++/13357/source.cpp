#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int d;
    cin >> d;
    
    vector<ll> money(d+1, 100);
    vector<ll> price(d+1, 0);
    
    for (int i=1; i<=d; i++) {
        cin >> price[i];
    }
    
    for (int i=2; i<=d; i++) {
        if (price[i-1] < price[i]) {
            if (money[i-1] / price[i-1] <= 100000) {
                money[i] = (money[i-1] / price[i-1]) * price[i] + (money[i-1] % price[i-1]);
            }
            else {
                money[i] = 100000 * price[i] + (money[i-1] - price[i-1] * 100000);
            }
        }
        else {
            money[i] = money[i-1];
        }
    }
    
    cout << money[d];
    
    return 0;
}
