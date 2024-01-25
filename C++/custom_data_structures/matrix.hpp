#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdio>

template <typename T>
class Matrix {
private:
	size_t row;
	size_t column;

    T mod;

	T** elements;
public:
	Matrix(size_t row, size_t column, T mod = 0) : row(row), column(column), mod(mod) {
		elements = new T * [row];

		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column]{};
		}
	}

	Matrix(size_t size, bool isIdentity = false, T mod = 0) : row(size), column(size), mod(mod) {
		elements = new T * [size];
		for (size_t i = 0; i < size; i++) {
			elements[i] = new T[size]{};

			if (isIdentity) {
				elements[i][i] = static_cast<T>(1);
			}
		}
	}

	Matrix(const Matrix& other) : row(other.row), column(other.column), mod(other.mod) {
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

		elements = new T*[row];
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
                    T product;

                    if (mod != 0) {
                        product = (this->elements[i][k] * other.elements[k][j]) % mod;
                    }
                    else {
                        product = this->elements[i][k] * other.elements[k][j];
                    }

					result.elements[i][j] += product;

                    if (mod != 0) {
                        result.elements[i][j] %= mod;
                    }
				}
			}
		}

		return result;
	}

	Matrix power(size_t exponent) {
		Matrix base(*this);
		Matrix result(row, true, mod);

		while (exponent > 0) {
			if (exponent % 2 == 1) {
				result = result * base;
			}
			exponent = exponent / 2;
			base = base * base;
		}

		return result;
	}

	size_t getRow(void) {
		return row;
	}

	size_t getColumn(void) {
		return column;
	}
};

#endif // __MATRIX_HPP__
