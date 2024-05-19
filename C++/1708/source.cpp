#include <bits/stdc++.h>
#ifndef __GEOMETRIC_LINE_HPP__
#define __GEOMETRIC_LINE_HPP__

#include <utility>

template <typename T>
class GeometricLine {
private:
	std::pair<T, T> start;
	std::pair<T, T> end;
public:
	GeometricLine() : start(std::make_pair(0, 0)), end(std::make_pair(0, 0)) {}

	GeometricLine(const std::pair<T, T>& start, const std::pair<T, T>& end) : start(start), end(end) {}

	GeometricLine& operator=(const GeometricLine& other) {
		this->start.first = other.start.first;
		this->start.second = other.start.second;
		this->end.first = other.end.first;
		this->end.second = other.end.second;

		return *this;
	}

	GeometricLine& update(const std::pair<T, T>& newStart, const std::pair<T, T>& newEnd) {
		this->start = newStart;
		this->end = newEnd;
		
		return *this;
	}

	T getCCW(const std::pair<T, T>& target) const {
		return (end.first - start.first) * (target.second - start.second) - (end.second - start.second) * (target.first - start.first);
	}

	bool cross(const GeometricLine& target) {
		const T ourCCW = this->getCCW(target.start) * this->getCCW(target.end);
		const T theirCCW = target.getCCW(this->start) * target.getCCW(this->end);

		if (ourCCW == 0 && theirCCW == 0) {
			if (this->start > target.end || target.start > this->end) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return (ourCCW <= 0 && theirCCW <= 0);
		}
	}

	const std::pair<T, T>& getStart(void) const {
		return start;
	}

	const std::pair<T, T>& getEnd(void) const {
		return end;
	}
	
	T lengthSquare(void) const {
	    T dx = end.first - start.first;
	    T dy = end.second - start.second;
	        
	    return dx * dx + dy * dy;
	}
};

#endif // !__GEOMETRIC_LINE_HPP__

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
