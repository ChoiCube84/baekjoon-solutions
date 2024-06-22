#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> set(N);
    for (int i=0; i<N; i++) {
        set[i] = i+1;
    }

    int total = N * (N + 1) / 2;
    
    if (total % 2 == 1) {
        cout << 0;
        return 0;
    }
    
    int halfOfTotal = total / 2;
    
    gp_hash_table<int, int> table;

    for (int i=0; i<(1<<(N/2)); i++) {
        int temp = i;
        int digit = 0;
        int sum = 0;

        while (temp) {
            sum += (temp % 2) * set[digit];
            temp >>= 1;
            digit++;
        }

        if (table.find(sum) == table.end()) {
            table[sum] = 1;
        }
        else {
            table[sum]++;
        }
    }

    unsigned long long int result = 0;
    
    for (int i=0; i<(1<<(N - (N/2))); i++) {
        int temp = i;
        int digit = N/2;
        int sum = 0;

        while (temp) {
            sum += (temp % 2) * set[digit];
            temp >>= 1;
            digit++;
        }

        if (table.find(halfOfTotal - sum) != table.end()) {
            result += table[halfOfTotal - sum];
        }
    }

    cout << result / 2;
    
    return 0;
}