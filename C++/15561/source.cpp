#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

template<int U, int V>
struct MyMonoid {
    int leftMax;
    int rightMax;
    int totalMax;
    int totalSum;

    MyMonoid() : leftMax(0), rightMax(0), totalMax(0), totalSum(0) {}
    MyMonoid(int K) : leftMax(U * K + V), rightMax(U * K + V), totalMax(U * K + V), totalSum(U * K + V) {}

    MyMonoid operator+(const MyMonoid& other) const {
        MyMonoid result;

        result.leftMax = max(leftMax, totalSum + other.leftMax);
        result.rightMax = max(rightMax + other.totalSum, other.rightMax);
        result.totalMax = max({
            totalMax,
            other.totalMax,
            rightMax + other.leftMax,
            result.leftMax,
            result.rightMax
        });
        result.totalSum = totalSum + other.totalSum;

        return result;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    
    return 0;
}