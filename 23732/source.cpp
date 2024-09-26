#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ull = unsigned long long int;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> doubled;
    for (int i=0; i<N-1; i++) {
        if (S[i] == S[i+1]) {
            doubled.push_back(i);
        }
    }

    ull result = N * (N + 1) / 2;

    ull prev = 0;

    for (int i=0; i<doubled.size(); i++) {
        ull n = doubled[i] - prev + 1;
        result -= n * (n + 1) / 2;
        prev = doubled[i] + 1;
    }

    ull n = N - prev;
    result -= n * (n + 1) / 2;

    cout << result;

    return 0;
}