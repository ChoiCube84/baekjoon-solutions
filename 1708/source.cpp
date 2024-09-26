#include <bits/stdc++.h>
#include "geometric_line.hpp"

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

class CCW_cmp {
private:
    pll origin;
   
public:
    CCW_cmp(const pll& origin) : origin(origin) {};
    bool operator()(const pll& A, const pll& B) {
        GeometricLine<ll> originToA(origin, A);
        ll ccw = originToA.getCCW(B);
       
        if (ccw < 0) {
            return false;
        }
        else if (ccw > 0) {
            return true;
        }
        else {
            GeometricLine<ll> originToB(origin, B);
            return originToA.lengthSquare() < originToB.lengthSquare();
        }
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int N;
    cin >> N;
   
    vector<pll> points(N);
   
    for (int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }
   
    sort(points.begin(), points.end());
   
    CCW_cmp cmp(points[0]);
    sort(points.begin() + 1, points.end(), cmp);
   
    GeometricLine<ll> currentLine(points[0], points[1]);
    stack<pll> convexHull;
   
    convexHull.push(points[0]);
    convexHull.push(points[1]);
   
    for (int i=2; i<N; i++) {
        while (convexHull.size() >= 2) {
            ll ccw = currentLine.getCCW(points[i]);
           
            if (ccw > 0) {
                break;
            }
            else {
                convexHull.pop();
                if (convexHull.size() == 1) {
                    break;
                }
            }
           
            pll B = convexHull.top();
            convexHull.pop();
            pll A = convexHull.top();
            convexHull.push(B);
           
            currentLine = GeometricLine<ll>(A, B);
        }
       
        currentLine = GeometricLine<ll>(convexHull.top(), points[i]);
        convexHull.push(points[i]);
    }
    
    cout << convexHull.size();
   
    return 0;
}
