#include <bits/extc++.h>
#include "matrix.hpp"

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct MyBool {
	bool value;

	MyBool() : value(false) {}
	MyBool(bool value) : value(value) {}

	MyBool operator+ (const MyBool& other) {
		return MyBool{value || other.value};
	}

	MyBool operator+= (const MyBool& other) {
		value = value || other.value;
		return *this;
	}

	MyBool operator* (const MyBool& other) {
		return MyBool{value && other.value};
	}

	MyBool operator*= (const MyBool& other) {
		value = value && other.value;
		return *this;
	}

	MyBool& operator%= (const MyBool& other) {
		value %= other.value;
		return *this;
	}

	bool operator!= (const MyBool& other) {
		return (this->value != other.value);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	Matrix<MyBool> a(N, N);

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> a[i][j].value;
		}
	}

	Matrix<MyBool> b(N, N);

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> b[i][j].value;
		}
	}

	Matrix<MyBool> c = a * b;
	int result = 0;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			result += c[i][j].value;
		}
	}

	cout << result;

	return 0;
}