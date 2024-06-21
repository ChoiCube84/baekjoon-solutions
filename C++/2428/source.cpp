#include <bits/extc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long double> F(N);
    for (int i=0; i<N; i++) {
        cin >> F[i];
    }
    
    sort(F.begin(), F.end());
    
    unsigned long long int result = 0;
    
    for (int i=0; i<N; i++) {
        result += (static_cast<int>(upper_bound(F.begin(), F.end(), (F[i] * 10.0 / 9.0)) - F.begin()) - i - 1);
    }
    
    cout << result;
    
    return 0;
}
