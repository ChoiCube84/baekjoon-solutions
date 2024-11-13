#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

ll GetDistance(const pll& A, const pll& B);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pll A, B, C;
	cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
	
	ll AB = GetDistance(A, B);
	ll BC = GetDistance(B, C);
	ll CA = GetDistance(C, A);
	
	if (AB > BC) {
		swap(AB, BC);
	}
	if (AB > CA) {
		swap(AB, CA);
	}
	if (BC > CA) {
		swap(BC, CA);
	}
	
	if (sqrtl(AB) + sqrtl(BC) > sqrtl(CA)) {
		if (AB == BC && BC == CA) {
			cout << "JungTriangle";
		}
		else if (AB == BC) {
			if (AB + BC < CA) {
				cout << "Dunkak2Triangle";
			}
			else if (AB + BC > CA) {
				cout << "Yeahkak2Triangle";
			}
			else {
				cout << "Jikkak2Triangle";
			}
		}
		else if (BC == CA) {
			cout << "Yeahkak2Triangle";
		}
		else {
			if (AB + BC < CA) {
				cout << "DunkakTriangle";
			}
			else if (AB + BC > CA) {
				cout << "YeahkakTriangle";
			}
			else {
				cout << "JikkakTriangle";
			}
		}
	}
	else {
		cout << 'X';
	}
	
	return 0;
}

ll GetDistance(const pll& A, const pll& B) {
	ll dx = A.first - B.first;
	ll dy = A.second - B.second;
	
    return dx * dx + dy * dy;
}