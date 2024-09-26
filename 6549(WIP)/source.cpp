#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

pll operator+(const pll& a, const pll& b) {
	pll result;

	result.first = min(a.first, b.first);
	result.second = a.second + b.second;
	
	return result;
}

struct MyMonoid {
	pll prefix_sum;
	pll suffix_sum;
	pll total_sum;
	pll maximum_sum;
	
	bool identity;
	
	MyMonoid(ll height=1, bool identity=true)
		: prefix_sum({height, 1}), suffix_sum({height, 1}), 
		total_sum({height, 1}), maximum_sum({height, 1}),
		identity(identity)
	{
		if (identity && height != 1) {
			identity = false;
		}
	}
	
	MyMonoid& operator=(const MyMonoid& other) {
		this->prefix_sum = other.prefix_sum;
		this->suffix_sum = other.suffix_sum;
		this->total_sum = other.total_sum;
		this->maximum_sum = other.maximum_sum;
		
		this->identity = other.identity;
		
		return *this;
	}
	
	MyMonoid operator*(const MyMonoid& other) const {
		MyMonoid result;
		
		if (this->identity) {
			if (!other.identity) {
				result = other;
			}
		}
		else if (other.identity) {
			result = *this;
		}
		else {
			result.prefix_sum = max(this->prefix_sum, this->total_sum + other.prefix_sum);
			result.suffix_sum = max(this->suffix_sum + other.total_sum, other.suffix_sum);
			result.total_sum = this->total_sum + other.total_sum;
			result.maximum_sum = max(
				max(this->maximum_sum, other.maximum_sum), 
				max(max(result.prefix_sum, result.suffix_sum), 
					max(result.total_sum, this->suffix_sum + other.prefix_sum)
				   )
			);
		}
		
		return result;
	}
	
	pll max(const pll& a, const pll& b) const {
		ll prod_a = a.first * a.second;
		ll prod_b = b.first * b.second;
		
		if (prod_a > prod_b) {
			return a;
		}
		else {
			return b;
		}
	}
};

bool solve(void);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve());
	
	return 0;
}

bool solve(void) {
	ll n;
	cin >> n;
	
	if (n == 0) {
		return false;
	}
	
	vector<MyMonoid> arr(n);
	for (ll i=0; i<n; i++) {
		ll h;
		cin >> h;
		
		arr[i] = MyMonoid(h, false);
	}
	
	cout << (make_pair(1, 2) + make_pair(4, 1)).second << '\n';
	
	MyMonoid total;
	for (ll i=0; i<n; i++) {
		total = total * arr[i];
		
		cout << "Prefix sum: height is " << total.prefix_sum.first << ", count is " << total.prefix_sum.second << ": " << total.prefix_sum.first * total.prefix_sum.second << '\n';
		cout << "Suffix sum: height is " << total.suffix_sum.first << ", count is " << total.suffix_sum.second << ": " << total.suffix_sum.first * total.suffix_sum.second << '\n';
		cout << "Total sum: height is " << total.total_sum.first << ", count is " << total.total_sum.second << ": " << total.total_sum.first * total.total_sum.second << '\n';
		cout << "Maximum sum: height is " << total.maximum_sum.first << ", count is " << total.maximum_sum.second << ": " << total.maximum_sum.first * total.maximum_sum.second << '\n';
		
		cout << '\n';
	}
	
	// SegmentTree segtree(arr);
	// auto result = segtree.query(0, n-1);
	
	// cout << (result.maximum_sum.first * result.maximum_sum.second) << '\n';
	
	return true;
}