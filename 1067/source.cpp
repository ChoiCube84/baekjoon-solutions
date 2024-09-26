#include <bits/stdc++.h>

using namespace std;

double const_pi(void) {
	return std::atan(1) * 4;
}

void FFT(std::vector<std::complex<double>>& a, const std::complex<double>& w) {
	int n = a.size();
	if (n == 1) return;

	std::vector<std::complex<double>> a_even(n / 2), a_odd(n / 2);
	for (int i = 0; i < n / 2; i++) {
		a_even[i] = a[2 * i];
		a_odd[i] = a[2 * i + 1];
	}

	std::complex<double> w_sq = w * w;
	FFT(a_even, w_sq);
	FFT(a_odd, w_sq);

	std::complex<double> w_i = 1;
	for (int i = 0; i < n / 2; i++) {
		a[i] = a_even[i] + w_i * a_odd[i];
		a[i + n / 2] = a_even[i] - w_i * a_odd[i];
		w_i *= w;
	}
}

std::vector<std::complex<double>> convolution(std::vector<std::complex<double>> a, std::vector<std::complex<double>> b, bool getIntegerResult = false) {
	int n = 1;
	double pi = const_pi();

	while (n <= a.size() || n <= b.size()) {
		n <<= 1;
	}
	n <<= 1;

	a.resize(n);
	b.resize(n);

	std::vector<std::complex<double>> c(n);

	std::complex<double> w(cos(2 * pi / n), sin(2 * pi / n));

	FFT(a, w);
	FFT(b, w);

	for (int i = 0; i < n; i++) {
		c[i] = a[i] * b[i];
	}

	FFT(c, std::complex(w.real(), -w.imag()));

	for (int i = 0; i < n; i++) {
		c[i] /= std::complex<double>(n, 0);
		if (getIntegerResult) {
			c[i] = std::complex(round(c[i].real()), round(c[i].imag()));
		}
	}

	return c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<complex<double>> X(2 * N);
	vector<complex<double>> Y(N);

	for (int i = 0; i < N; i++) {
		int tempNum;
		cin >> tempNum;
		X[i] = X[i + N] = complex<double>(tempNum, 0);
	}

	for (int i = 0; i < N; i++) {
		int tempNum;
		cin >> tempNum;
		Y[N - i - 1] = complex<double>(tempNum, 0);
	}

	auto Z = convolution(X, Y, true);

	int result = 0;

	for (auto& i : Z) {
		result = max(result, static_cast<int>(i.real()));
	}

	cout << result;

	return 0;
}
