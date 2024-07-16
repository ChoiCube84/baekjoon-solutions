#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

ll lengthSquared(const pll& vec);
long double length(const pll& A, const pll& B);

vector<vector<pll>> getCombinations(const vector<pll>& points);
pll findMinimumSum(const vector<pll>& vectors);

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

ll lengthSquared(const pll& vec) {
    return vec.first * vec.first + vec.second * vec.second;
}

long double length(const pll& vec) {
    return sqrtl(lengthSquared(vec));
}

vector<vector<pll>> getCombinations(const vector<pll>& points) {
    vector<vector<pll>> combinations;
    int N = points.size();

    if (N == 2) {
        vector<pll> combination;
        
        combination.emplace_back(points[1].first - points[0].first, points[1].second - points[0].second);
        combinations.push_back(combination);
        
        return combinations;
    }

    for (int i=1; i<N; i++) {
        vector<pll> newPoints = points;
        pll currVector = make_pair(points[i].first - points[0].first, points[i].second - points[0].second);

        newPoints.erase(newPoints.begin());
        newPoints.erase(newPoints.begin() + i - 1);

        vector<vector<pll>> restCombinations = getCombinations(newPoints);

        for (auto& combination : restCombinations) {
            combination.emplace_back(currVector);
            combinations.emplace_back(combination);
        }
    }

    return combinations;
}

pll findMinimumSum(const vector<pll>& vectors) {
    int N = vectors.size();
    bool first = true;
    pll best;

    for (int i=0; i<(1<<N); i++) {
        pll sum = make_pair(0LL, 0LL);
        
        for (int j=0; j<N; j++) {
            if (i & (1 << j)) {
                sum.first += vectors[j].first;
                sum.second += vectors[j].second;
            } else {
                sum.first -= vectors[j].first;
                sum.second -= vectors[j].second;
            }
        }
        
        if (first || lengthSquared(sum) < lengthSquared(best)) {
            best = sum;
            first = false;
        }
    }

    return best;
}

void simulate(void) {
    int N;
    cin >> N;

    vector<pll> points(N);
    for (int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<vector<pll>> combinations = getCombinations(points);

    bool first = true;
    pll best;

    for (auto& combination : combinations) {
        pll sum = findMinimumSum(combination);
        if (first || lengthSquared(sum) < lengthSquared(best)) {
            best = sum;
            first = false;
        }
    }

    cout << setprecision(15) << fixed << length(best) << '\n';
}