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

	T getCCW(const std::pair<T, T>& target) const {
		return (end.first - start.first) * (target.second - start.second) - (end.second - start.second) * (target.first - start.first);
	}

	bool cross(const GeometricLine& target) {
		const T ourCCW = this->getCCW(target.start) * this->getCCW(target.end);
		const T theirCCW = target.getCCW(this->start) * target.getCCW(this->end);

		if (ourCCW == 0 && theirCCW == 0) {
			if (this->start > target.end || target.start > this->end) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return (ourCCW <= 0 && theirCCW <= 0);
		}
	}

	const std::pair<T, T>& getStart(void) const {
		return start;
	}

	const std::pair<T, T>& getEnd(void) const {
		return end;
	}
};

#endif // !__GEOMETRIC_LINE_HPP__
