#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

ll lengthSquare(const pll& vec);
long double length(const pll& A, const pll& B);
pll findMinimumVector(vector<pll> points);
void simulate(void);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        simulate();
    }

    return 0;
}

ll lengthSquare(const pll& vec) {
    return vec.first * vec.first + vec.second * vec.second;
}

long double length(const pll& vec) {
    return sqrtl(lengthSquare(vec));
}

pair<pll, bool> findMinimumVector(vector<pll> points) { // WIP
    int N = points.size();
    pll best = make_pair(-1LL, -1LL);

    if (N == 0) {
        return make_pair(0LL, 0LL);
    }

    for (int i=1; i<N; i++) {
        vector<pll> newPoints = points;

        newPoints.erase(newPoints.begin());
        newPoints.erase(newPoints.begin() + i);

        bool reversible = false;
        pll cand1, cand2, candidate;
        ll dx = points[0].first - points[i].first;
        ll dy = points[0].second - points[i].second;

        auto temp = findMinimumVector(newPoints);
        pll minimumVector = temp.first;

        cand1.first = dx + minimumVector.first;
        cand1.second = dy + minimumVector.second;

        cand2.first = minimumVector.first - dx;
        cand2.second = minimumVector.second - dy;

        if (lengthSquare(cand1) < lengthSquare(cand2) || cand1 == cand2) {
            candidate = cand1;
        }
        else if (lengthSquare(cand1) == lengthSquare(cand2)) {
            candidate = cand1;
            reversible = true;
        }
        else {
            candidate = cand2;
        }

        if (best.first == -1 || lengthSquare(candidate) < lengthSquare(best)) {
            best = candidate;
        }
    }

    return make_pair(best, reversible);
}

void simulate(void) {
    int N;
    cin >> N;

    vector<pll> points(N);
    for (int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    cout << setprecision(15) << fixed << length(findMinimumVector(points)) << '\n';
}