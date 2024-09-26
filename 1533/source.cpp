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

    ull N, S, E, T;
    cin >> N >> S >> E >> T;

    Matrix<ull> matrix(5 * N, 5 * N, false, 1000003);

    for (ull i=0; i<N; i++) {
        matrix[5 * i + 4][5 * i + 3] = 1;
        matrix[5 * i + 3][5 * i + 2] = 1;
        matrix[5 * i + 2][5 * i + 1] = 1;
        matrix[5 * i + 1][5 * i + 0] = 1;

        string input;
        cin >> input;

        for (ull j=0; j<N; j++) {
            ull dist = input[j] - '0';
            if (dist != 0) {
                matrix[5 * i][5 * j - 1 + dist] = 1;
            }
        }
    }

    Matrix<ull> result = matrix.power(T);

    cout << result[5 * (S-1)][5 * (E-1)];

    return 0;
}