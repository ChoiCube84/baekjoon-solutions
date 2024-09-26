#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        string n;
        cin >> n;

        bool decreasing = false;
        bool failed = false;

        int prev = 0;

        for (int i=0; i<n.size(); i++) {
            int curr = n[i] - '0';

            if (!decreasing) {
                if (prev > curr) {
                    decreasing = true;
                }
                prev = curr;
            }
            else {
                if (failed) {
                    n[i] = prev + '0';
                }
                else {
                    if (prev < curr) {
                        failed = true;
                        n[i] = prev + '0';
                    }
                    else {
                        prev = curr;
                    }
                }
            } 
        }

        cout << n << "\n";
    }

    return 0;
}