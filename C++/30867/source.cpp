#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, N;
    cin >> L >> N;

    string input;
    cin >> input;

    for (int start=0; start<L; start++) {
        if (input[start] != 'w') {
            continue;
        }

        int end;
        for (end=start+1; end<L; end++) {
            if (input[end] != 'w' && input[end] != 'h') {
                end--;
                break;
            }
        }

        vector<int> positions;
        for (int i=start; i<=end; i++) {
            if (input[i] == 'h') {
                positions.emplace_back(i);
                input[i] = 'w';
            }
        }

        if (positions.size() > 0) {
            positions[0] = max(start, positions[0] - N);
            for (int i=1; i<positions.size(); i++) {
                positions[i] = max(positions[i-1] + 1, positions[i] - N);
            }

            for (auto& position : positions) {
                input[position] = 'h';
            }
        }

        start = end+1;
    }

    cout << input;

    return 0;
}