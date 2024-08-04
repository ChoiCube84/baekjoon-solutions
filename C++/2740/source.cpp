#include <bits/extc++.h>
#include "matrix.hpp"

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	Matrix<int> a(N, M);

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> a[i][j];
		}
	}

	int K;
	cin >> M >> K;

	Matrix<int> b(M, K);

	for (int i=0; i<M; i++) {
		for (int j=0; j<K; j++) {
			cin >> b[i][j];
		}
	}

	Matrix<int> c = a * b;

	for (int i=0; i<N; i++) {
		for (int j=0; j<K; j++) {
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}