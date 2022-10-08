#include <iostream>
#include <Windows.h>
#include <sstream>
#include <string>

template <typename T> std::string toString(T const& numeric) {
	std::ostringstream stream;
	stream << numeric;
	return stream.str();
}

template <typename T> class ThreeValues {
public:
	ThreeValues(T a, T b, T c) : a_(a), b_(b), c_(c) {}
	T calculateSum() const { return a_ + b_ + c_; }
	T maxValue() const { return a_ > b_ ? (a_ > c_ ? a_ : c_) : (b_ > c_ ? b_ : c_); }
	T minValue() const { return a_ < b_ ? (a_ < c_ ? a_ : c_) : (b_ < c_ ? b_ : c_); }
private:
	T a_, b_, c_;
};