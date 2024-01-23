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

	GeometricLine(const std::pair<T, T>& start, const std::pair<T, T>& end) : start(start), end(end) {
		if (this->start > this->end) {
			swap(this->end, this->start);
		}
	}

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

        if (this->start > this->end) {
            swap(this->end, this->start);
        }

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
};

#endif // !__GEOMETRIC_LINE_HPP__

#ifndef __DISJOINT_SET_HPP__
#define __DISJOINT_SET_HPP__

#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        else {
            return parent[u] = find(parent[u]);
        }
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            if (rank[u] > rank[v]) {
                std::swap(u, v);
            }

            parent[u] = v;

            if (rank[u] == rank[v]) {
                rank[v]++;
            }
        }
    }
};

#endif // !__DISJOINT_SET_HPP__

using namespace std;

using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<GeometricLine<ll>> lines(N);
    DisjointSet diset(N);
    vector<int> lineCount(N, 0);

    for (int i=0; i<N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        lines[i].update({x1, y1}, {x2, y2});
    }

    for (int i=0; i<N; i++) {
        GeometricLine<ll>& curr = lines[i];

        for (int j=0; j<N; j++) {
            GeometricLine<ll>& next = lines[j];

            if (diset.find(i) != diset.find(j) && curr.cross(next)) {
                diset.merge(i, j);
            }
        }
    }

    int groups = 0;
    int maximum = INT_MIN;
    for (int i=0; i<N; i++) {
        int curr = diset.find(i);

        if (lineCount[curr] == 0) {
            groups++;
        }

        lineCount[curr]++;
        maximum = max(maximum, lineCount[curr]);
    }

    cout << groups << "\n" << maximum;

    return 0;
}
