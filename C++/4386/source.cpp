#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using pos = pair<long double, long double>;

long double distance(const pos& A, const pos& B);
long double prim (const vector<pos>& points);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pos> points(n);

    for (int i=0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    cout << fixed;
    cout.precision(2);

    cout << prim(points);

    return 0;
}

long double prim (const vector<pos>& points) {
    size_t n = points.size();

    vector<long double> distFromTree(n, INT_MAX);
    vector<bool> visited(n, false);

    long double result = 0;

    distFromTree[0] = 0;

    for(int i=0; i<n; i++) {
        int curr = 0;
        long double minDistFromTree = INT_MAX;

        for (int candidate=0; candidate<n; candidate++) {
            if(!visited[candidate] && minDistFromTree > distFromTree[candidate]) {
                minDistFromTree = distFromTree[candidate];
                curr = candidate;
            }
        }

        visited[curr] = true;
        result += minDistFromTree;

        for (int next=0; next<n; next++) {
            if (!visited[next]) {
                distFromTree[next] = fmin(distFromTree[next], distance(points[curr], points[next]));
            }
        }
    }

    return result;
}

long double distance(const pos& A, const pos& B) {
    auto dx = A.first - B.first;
    auto dy = A.second - B.second;

    return sqrtl(dx * dx + dy * dy);
}
