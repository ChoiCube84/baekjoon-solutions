#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <utility>

template <typename T>
class Matrix {
private:
	size_t row;
	size_t column;

	T mod;

	T** elements;

	void clearElements(void) {
		for (size_t i = 0; i < row; i++) {
			delete[] elements[i];
		}
		delete[] elements;
	}
public:
	Matrix() : row(0), column(0), mod(0), elements(nullptr) {}

	Matrix(size_t row, size_t column, bool identity = false, T mod = 0) : row(row), column(column), mod(mod) {
		elements = new T * [row];

		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column];

			for (size_t j = 0; j < column; j++) {
				elements[i][j] = identity ? (i == j ? 1 : 0) : 0;
			}
		}
	}

	Matrix(const Matrix& other) : mod(other.mod) {
		this->row = other.row;
		this->column = other.column;
		
		elements = new T * [row];

		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column];

			for (size_t j = 0; j < column; j++) {
				elements[i][j] = other.elements[i][j];
			}
		}
	}

	~Matrix() {
		clearElements();
	}

	T* operator[] (size_t idx) {
		return elements[idx];
	}

	const T* operator[] (size_t idx) const {
		return elements[idx];
	}

	Matrix& operator= (const Matrix& other) {
		if (this == &other) {
			return *this;
		}

		clearElements();

		this->row = other.row;
		this->column = other.column;

		elements = new T * [row];
		for (size_t i = 0; i < row; i++) {
			elements[i] = new T[column];

			for (size_t j = 0; j < column; j++) {
				elements[i][j] = other.elements[i][j];
			}
		}

		return *this;
	}

	Matrix operator+ (const Matrix& other) {
		Matrix result(*this);

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				result.elements[i][j] += other.elements[i][j];

				if (mod != 0) {
					result.elements[i][j] %= mod;
				}
			}
		}

		return result;
	}

	Matrix& operator+= (const Matrix& other) {
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				elements[i][j] += other.elements[i][j];

				if (mod != 0) {
					elements[i][j] %= mod;
				}
			}
		}

		return *this;
	}

	Matrix operator- (const Matrix& other) {
		Matrix result(*this);

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				result.elements[i][j] -= other.elements[i][j];

				if (mod != 0) {
					result.elements[i][j] %= mod;
				}
			}
		}

		return result;
	}

	Matrix& operator-= (const Matrix& other) {
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				elements[i][j] -= other.elements[i][j];

				if (mod != 0) {
					elements[i][j] %= mod;
				}
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
					T product = this->elements[i][k] * other.elements[k][j];

					if (mod != 0) {
						product %= mod;
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
		Matrix result(row, column, true, mod);

		while (exponent > 0) {
			if (exponent % 2 == 1) {
				result = result * base;
			}
			exponent = exponent / 2;
			base = base * base;
		}

		return result;
	}

	T trace(void) {
		T result = 0;
		
		for (size_t i = 0; i < row; i++) {
			result += elements[i][i];
		}

		return result;
	}

	T determinant(void) { // WIP
		return 0;
	}

	Matrix transpose(void) {
		Matrix result(column, row);

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < column; j++) {
				result.elements[j][i] = elements[i][j];
			}
		}

		return result;
	}

	const std::pair<size_t, size_t> size(void) const {
		return std::make_pair(row, column);
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix matrix) { 
		for (size_t i = 0; i < matrix.row; i++) {
			for (size_t j = 0; j < matrix.column; j++) {
				os << matrix.elements[i][j] << ' ';
			}
			os << '\n';
		}

		return os;
	}
};

#endif // __MATRIX_HPP__
