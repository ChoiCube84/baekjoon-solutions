#include <bits/extc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int H1, B1, H2, B2;
    cin >> H1 >> B1 >> H2 >> B2;
    
    int sum1 = H1 * 3 + B1;
    int sum2 = H2 * 3 + B2;
    
    if (sum1 == sum2) {
        cout << "NO SCORE";
        return 0;
    }
    else if (sum1 > sum2) {
        cout << 1 << " ";
    }
    else {
        cout << 2 << " ";
    }
    
    cout << abs(sum1 - sum2);
    
    return 0;
}
