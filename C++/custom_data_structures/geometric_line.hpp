#ifndef __GEOMETRIC_LINE_HPP__
#define __GEOMETRIC_LINE_HPP__

#include <utility>

template <typename T>
struct GeometricLine {
	std::pair<T, T> start;
	std::pair<T, T> end;

	GeometricLine() : start(std::make_pair(0, 0)), end(std::make_pair(0, 0)) {}

	GeometricLine(const std::pair<T, T>& start, const std::pair<T, T>& end) : start(start), end(end) {
		if (this->start > this->end) {
			swap(this->end, this->start);
		}
	}

	GeometricLine& operator=(const GeometricLine& other) {
		this->start.first = other.start.first;
		this->start.second = other.start.second;
		this->end.first = other.end.first;
		this->end.second = other.end.second;

		return *this;
	}

	GeometricLine& update(const std::pair<T, T>& newStart, const std::pair<T, T>& newEnd) {
		this->start = newStart;
		this->end = newEnd;

		return *this;
	}

	T getCCW(const std::pair<T, T>& target) const {
		return (end.first - start.first) * (target.second - start.second) - (end.second - start.second) * (target.first - start.first);
	}

	T lengthSquare(void) const {
		T dx = end.first - start.first;
		T dy = end.second - start.second;

		return dx * dx + dy * dy;
	}
};

#endif // !__GEOMETRIC_LINE_HPP__
