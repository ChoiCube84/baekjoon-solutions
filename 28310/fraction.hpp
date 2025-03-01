#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__

#include <numeric>
#include <stdexcept>

template <typename T>
struct Fraction {
	T numerator;
	T denominator;

	void simplify(void) {
		if (numerator == static_cast<T>(0)) {
			denominator = static_cast<T>(1);
		}
		else {
			T gcd = std::gcd(numerator, denominator);

			if (gcd != static_cast<T>(0)) {
				numerator /= gcd;
				denominator /= gcd;
			}

			if (denominator < static_cast<T>(0)) {
				numerator = -numerator;
				denominator = -denominator;
			}
		}
	}

	Fraction() : numerator(static_cast<T>(0)), denominator(static_cast<T>(1)) {}
	Fraction(T integer) : numerator(integer), denominator(static_cast<T>(1)) {}
	Fraction(T numerator, T denominator) : numerator(numerator), denominator(denominator) {
		if (denominator == static_cast<T>(0)) {
			throw std::overflow_error("Cannot divide by zero.");
		}
		simplify();
	}

	Fraction operator+(const Fraction& other) const {
		T newNumerator = numerator * other.denominator + other.numerator * denominator;
		T newDenominator = denominator * other.denominator;

		return Fraction(newNumerator, newDenominator);
	}

	Fraction& operator+=(const Fraction& other) {
		T new_numerator = other.numerator * this->denominator;
		
		this->numerator *= other.denominator;
		this->denominator *= other.denominator;

		this->numerator += new_numerator;
		
		simplify();

		return *this;
	}

	Fraction operator-(const Fraction& other) const {
		T new_numerator = numerator * other.denominator - other.numerator * denominator;
		T new_denominator = denominator * other.denominator;

		return Fraction(new_numerator, new_denominator);
	}

	Fraction& operator-=(const Fraction& other) {
		T new_numerator = other.numerator * this->denominator;
		
		this->numerator *= other.denominator;
		this->denuminator *= other.denominator;

		this->numerator -= new_numerator;

		simplify();

		return *this;
	}

	Fraction operator*(const Fraction& other) const {
		T new_numerator = numerator * other.numerator;
		T new_denominator = denominator * other.denominator;

		return Fraction(new_numerator, new_denominator);
	}

	Fraction& operator*=(const Fraction& other) {
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;

		simplify();

		return *this;
	}

	Fraction operator/(const Fraction& other) const {
		return (*this * other.inverse());
	}

	Fraction& operator/=(const Fraction& other) {
		return (*this *= other.inverse());
	}

	bool operator<(const Fraction& other) {
		return (this->numerator * other.denominator) < (other.numerator * this->denominator);
	}

	Fraction inverse(void) const {
		return Fraction(denominator, numerator);
	}

	operator double() const {
		return static_cast<double>(numerator) / static_cast<double>(denominator);
	}

	operator long double() const {
		return static_cast<long double>(numerator) / static_cast<long double>(denominator);
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& value) { 
        if (value.denominator == 1) {
			os << value.numerator;
		}
		else {
			os << value.numerator << '/' << value.denominator;
		}

		return os;
    }
};

#endif // __FRACTION_HPP__
