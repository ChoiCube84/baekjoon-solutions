#ifndef __GEOMETRIC_LINE_HPP__
#define __GEOMETRIC_LINE_HPP__

#include <utility>

template <typename T>
class GeometricLine {
private:
	std::pair<T, T> start;
	std::pair<T, T> end;

public:
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

	void Update(const std::pair<T, T>& start, const std::pair<T, T>& end) {
		this->start = start;
		this->end = end;

		if (this->start > this->end) {
			swap(this->end, this->start);
		}
	}

	const std::pair<T, T>& GetStart(void) const {
		return start;
	}

	const std::pair<T, T>& GetEnd(void) const {
		return end;
	}
};

#endif // !__GEOMETRIC_LINE_HPP__
