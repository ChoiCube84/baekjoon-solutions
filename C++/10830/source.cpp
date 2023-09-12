#include <bits/stdc++.h>

template <typename T>
class Matrix {
public:
	size_t row;
	size_t column;

	T** elements;
public:
	Matrix(size_t row, size_t column) : row(row), column(column) {
		elements = new T * [row];

		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column]{};
		}
	}

	Matrix(size_t size, bool isIdentity = false) : row(size), column(size) {
		elements = new T * [size];
		for (size_t i = 0; i < size; i++) {
			elements[i] = new T[size]{};

			if (isIdentity == true) {
				elements[i][i] = static_cast<T>(1);
			}
		}
	}

	Matrix(const Matrix& other) : row(other.row), column(other.column) {
		elements = new T * [row];

		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column];

			for (size_t j = 0; j < column; j++) {
				elements[i][j] = other.elements[i][j];
			}
		}
	}

	~Matrix() {
		for (size_t i = 0; i < row; i++) {
			delete[] elements[i];
		}
		delete[] elements;
	}

	T* operator[] (size_t idx) {
		return elements[idx];
	}

	Matrix& operator= (const Matrix& other) {
		if (this == &other) {
			return *this;
		}

		for (size_t i = 0; i < row; i++) {
			delete[] elements[i];
		}
		delete[] elements;

		row = other.row;
		column = other.column;

		elements = new T * [row];
		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column];

			for (size_t j = 0; j < column; j++) {
				elements[i][j] = other.elements[i][j];
			}
		}

		return *this;
	}

	Matrix operator* (const Matrix& other) {
		Matrix result(this->row, other.column);

		for (size_t i = 0; i < result.row; i++) {
			for (size_t j = 0; j < result.column; j++) {
				result.elements[i][j] = 0;

				for (size_t k = 0; k < this->column; k++) {
					result.elements[i][j] += (this->elements[i][k] * other.elements[k][j] % static_cast<T>(1000));
					result.elements[i][j] %= static_cast<T>(1000);
				}
			}
		}

		return result;
	}

	Matrix power(size_t exponent) {
		Matrix base(*this);
		Matrix result(row, true);

		while (exponent > 0) {
			if (exponent % 2 == 1) {
				result = result * base;
			}
			exponent = exponent / 2;
			base = base * base;
		}

		return result;
	}
};

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;

    Matrix<long long> mat(A);

    for (long long i = 0; i < A; i++) {
        for (long long j = 0; j < A; j++) {
            cin >> mat[i][j];
        }
    }

    Matrix<long long> result(mat.power(B));

    for (size_t i = 0; i < mat.row; i++) {
        for (size_t j = 0; j < mat.column; j++) {
            cout << result.elements[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
