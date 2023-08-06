#include <bits/stdc++.h>

using namespace std;

struct Matrix {
	unsigned long long int leftUp, rightUp, leftDown, rightDown;

	Matrix(unsigned long long int leftUp, unsigned long long int rightUp, unsigned long long int leftDown, unsigned long long int rightDown) : leftUp(leftUp), rightUp(rightUp), leftDown(leftDown), rightDown(rightDown) {}
	
	Matrix operator*(const Matrix& other) {
		unsigned long long int a, b, c, d, e, f, g, h;
		a = this->leftUp;
		b = this->rightUp;
		c = this->leftDown;
		d = this->rightDown;

		e = other.leftUp;
		f = other.rightUp;
		g = other.leftDown;
		h = other.rightDown;

		Matrix result((a * e + b * g) % 1000000007, (a * f + b * h) % 1000000007, (c * e + d * g) % 1000000007, (c * f + d * h) % 1000000007);

		return result;
	}

	pair<unsigned long long int, unsigned long long int> operator*(const pair<unsigned long long int, unsigned long long int>& other) {
		unsigned long long int a, b, c, d, e, f;

		a = this->leftUp;
		b = this->rightUp;
		c = this->leftDown;
		d = this->rightDown;

		e = other.first;
		f = other.second;

		pair<unsigned long long int, unsigned long long int> result = { (a * e + b * f) % 1000000007, (c * e + d * f) % 1000000007 };

		return result;
	}
};

Matrix matPow(Matrix A, unsigned long long int n);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long int n;
	cin >> n;

	pair<unsigned long long int, unsigned long long int> fibo = { 1, 0 };

	fibo = matPow({ 1, 1, 1, 0 }, n - 1) * fibo;

	cout << fibo.first;

	return 0;
}

Matrix matPow(Matrix A, unsigned long long int n) {
	if (n == 0) {
		return { 1, 0, 0, 1 };
	}
	if (n == 1) {
		return A;
	}
	else {
		Matrix half = matPow(A, n / 2);
		if (n % 2 == 0) {
			return half * half;
		}
		else {
			return half * half * A;
		}
	}
}
