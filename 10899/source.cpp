#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long int;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ull P, N, maximumPenalty = 0;
    cin >> P >> N;
    
    vector<ull> times(N);
    
    for (ull i=0; i<N; i++) {
        cin >> times[i];
    }
    
    sort(times.begin(), times.end());
    
    ull i;
    ull timePassed = P - 1;
    
    for (i=0; i<N; i++) {
        if (times[i] <= timePassed) {
            maximumPenalty += timePassed;
            timePassed -= times[i];
        }
        else {
            break;
        }
    }
    
    cout << i << " " << maximumPenalty;
    
    return 0;
}
