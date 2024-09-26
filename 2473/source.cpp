#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> liquids(N);

    for (int i=0; i<N; i++) {
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    ll minimum = LLONG_MAX;
    tuple<int, int, int> min_set;

    for (int middle = 1; middle < N - 1; middle++) {
        int start = 0;
        int end = N - 1;

        while (start < middle && middle < end) {
            ll temp = liquids[start] + liquids[middle] + liquids[end];

            if (temp == 0) {
                cout << liquids[start] << " " << liquids[middle] << " " << liquids[end];
                return 0;
            }
            else if (abs(temp) < abs(minimum)) {
                minimum = temp;
                min_set = make_tuple(liquids[start], liquids[middle], liquids[end]);
            }

            if (temp > 0) {
                end--;
            }
            else {
                start++;
            }
        }
    }

    cout << get<0>(min_set) << " " << get<1>(min_set) << " " << get<2>(min_set);

    return 0;
}
