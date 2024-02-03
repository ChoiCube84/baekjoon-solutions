#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll T, n, m;
    cin >> T;

    cin >> n;
    vector<ll> A(n);

    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<ll> B(m);

    for (int i=0; i<m; i++) {
        cin >> B[i];
    }

    vector<ll> subSeqSumA;
    vector<ll> subSeqSumB;

    for (int i=0; i<n; i++) {
        ll sum = A[i];
        subSeqSumA.emplace_back(sum);

        for (int j=i+1; j<n; j++) {
            sum += A[j];
            subSeqSumA.emplace_back(sum);
        }
    }

    for (int i=0; i<m; i++) {
        ll sum = B[i];
        subSeqSumB.emplace_back(sum);

        for (int j=i+1; j<m; j++) {
            sum += B[j];
            subSeqSumB.emplace_back(sum);
        }
    }

    sort(subSeqSumB.begin(), subSeqSumB.end());

    ll result = 0;
    for (auto& sumA : subSeqSumA) {
        ll target = T - sumA;

        result += upper_bound(subSeqSumB.begin(), subSeqSumB.end(), target)
                - lower_bound(subSeqSumB.begin(), subSeqSumB.end(), target);;
    }

    cout << result;

    return 0;
}
