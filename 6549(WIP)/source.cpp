#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

using vpll = vector<pll>;

// Rectangle information is stored by pll
// first is height, second is width

ll area(const pll& a) {
	return a.first * a.second;
}

pll operator+(const pll& a, const pll& b) {
	pll result;
	
	result.first = min(a.first, b.first);
	result.second = a.second + b.second;
	
	return result;
}

vpll operator+(const vpll& a, const vpll& b) {
	vpll result;

	for (auto& A: a) {
		for (auto& B: b) {
			pll AB = A+B;
			ll prod_AB = area(AB);
			
			if (result.empty()) {
				if (prod_AB > 0) {
					result.emplace_back(AB);
				}
			}
			else {
				ll prod_result = area(result[0]);

				if (prod_result < prod_AB) {
					result = {AB};
				}
				else if (prod_result == prod_AB) {
					result.emplace_back(AB);
				}
			}
		}
	}
	
	return result;
}

vpll max(const vpll& a, const vpll& b) {
	if (a.empty()) {
		return b;
	}
	else if (b.empty()) {
		return a;
	}
	
	ll prod_a = area(a[0]);
	ll prod_b = area(b[0]);

	vpll concat = a;
	concat.insert(concat.end(), b.begin(), b.end());

	if (prod_a > prod_b) {
		return a;
	}
	else if (prod_a < prod_b) {
		return b;
	}
	else {
		return concat;
	}
}

struct MyMonoid {
	vpll prefix_sums;
	vpll suffix_sums;
	vpll total_sum;
	vpll maximum_sums;
	
	MyMonoid(ll height=0)
		: prefix_sums({make_pair(height, 1LL)}), 
		suffix_sums({make_pair(height, 1LL)}), 
		total_sum({make_pair(height, 1LL)}), 
		maximum_sums({make_pair(height, 1LL)}) {}
	
	MyMonoid& operator=(const MyMonoid& other) {
		this->prefix_sums = other.prefix_sums;
		this->suffix_sums = other.suffix_sums;
		this->total_sum = other.total_sum;
		this->maximum_sums = other.maximum_sums;
		
		return *this;
	}
	
	MyMonoid operator*(const MyMonoid& other) const {
		MyMonoid result;
		
		result.prefix_sums = max(this->prefix_sums, this->total_sum + other.prefix_sums);
		result.suffix_sums = max(this->suffix_sums + other.total_sum, other.suffix_sums);
		result.total_sum = this->total_sum + other.total_sum;
		result.maximum_sums = max(
			max(this->maximum_sums, other.maximum_sums), 
			max(max(result.prefix_sums, result.suffix_sums), 
				max(result.total_sum, this->suffix_sums + other.prefix_sums)
			   )
		);
		
		return result;
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
		
		arr[i] = MyMonoid(h);
	}
	
	MyMonoid total = arr[0];
	
	for (ll i=1; i<n; i++) {
		total = total * arr[i];
		
		// cout << "Prefix sums: ";
		// for (auto& ps: total.prefix_sums) {
		// 	cout << '(' << ps.first << ", " << ps.second << ") ";
		// }
		// cout << '\n';
		
		// cout << "Suffix sums: ";
		// for (auto& ss: total.suffix_sums) {
		// 	cout << '(' << ss.first << ", " << ss.second << ") ";
		// }
		// cout << '\n';
		
		// cout << "Total sum: ";
		// for (auto& ts: total.total_sum) {
		// 	cout << '(' << ts.first << ", " << ts.second << ") ";
		// }
		// cout << '\n';
		
		// cout << "Maximum sums: ";
		// for (auto& ms: total.maximum_sums) {
		// 	cout << '(' << ms.first << ", " << ms.second << ") ";
		// }
		// cout << '\n';
		
		// cout << '\n';
	}
	
	cout << area(total.maximum_sums[0]) << '\n';
	
	return true;
}