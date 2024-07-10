#include <bits/extc++.h>
#include "matrix.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S, E, T;
    cin >> N >> S >> E >> T;

    Matrix<int> matrix(N, N, false, 1000003);

    for (int i=0; i<N; i++) {
        string input;
        cin >> input;
        for (int j=0; j<N; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    Matrix<int> result = matrix.power(T); // Wrong apporach!
    
    cout << result[S-1][E-1];

    return 0;
}