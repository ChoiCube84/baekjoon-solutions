#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dices(N);
    for (int i=0; i<N; i++) {
        cin >> dices[i];
    }

    sort(dices.begin(), dices.end());
    
    vector<int> towers;
    towers.emplace_back(0);

    for (auto& dice : dices) {
        bool found = false;
        
        for (auto& tower : towers) {
            if (tower <= dice) {
                tower++;
                found = true;
            }

            if (found) {
                break;
            }
        }

        if (!found) {
            towers.emplace_back(1);
        }
    }

    cout << towers.size();

    return 0;
}