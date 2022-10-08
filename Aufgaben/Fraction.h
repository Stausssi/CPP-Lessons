#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	Fraction(double number);
	std::string getFraction();

	Fraction operator+ (Fraction const& fraction);
	Fraction& operator+= (Fraction const& fraction);
	Fraction operator- (Fraction const& fraction);
	Fraction& operator-= (Fraction const& fraction);
	Fraction operator* (Fraction const& fraction);
	Fraction& operator*= (Fraction const& fraction);
	Fraction operator/ (Fraction const& fraction);
	Fraction& operator/= (Fraction const& fraction);
	Fraction& reduce();
	double toDouble();
private:
	int numerator_;
	int denominator_;
	bool isOverflowing(int a, int b);
	int getGCD(int a, int b);
};


Fraction::Fraction(int numerator, int denominator) {
	numerator_ = numerator;
	if (denominator == 0) throw std::invalid_argument("Can't divide by 0!");
	else denominator_ = denominator;
}

Fraction::Fraction(double number) {
	std::string numberAsString = std::to_string(number);
	numberAsString.erase(numberAsString.find_last_not_of('0') + 1, std::string::npos); // This removes the trailing zeroes

	denominator_ = pow(10, numberAsString.length());
	numerator_ = number * denominator_;
	reduce();
}

std::string Fraction::getFraction() {
	return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}

Fraction& Fraction::reduce() {
	int gcd = getGCD(numerator_, denominator_);
	numerator_ /= gcd;
	denominator_ /= gcd;
	return *this;
}

double Fraction::toDouble() {
	return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

Fraction Fraction::operator+(Fraction const& fraction) {
	Fraction tempFrac = *this;
	tempFrac.numerator_ = tempFrac.numerator_ * fraction.denominator_ + fraction.numerator_ * tempFrac.denominator_;
	tempFrac.denominator_ = tempFrac.denominator_ * fraction.denominator_;
	return tempFrac.reduce();
}

Fraction& Fraction::operator+=(Fraction const& fraction) {
	numerator_ = numerator_ * fraction.denominator_ + fraction.numerator_ * denominator_;
	denominator_ = denominator_ * fraction.denominator_;
	reduce();
	return *this;
}

Fraction Fraction::operator-(Fraction const& fraction) {
	Fraction tempFrac = *this;
	tempFrac.numerator_ = tempFrac.numerator_ * fraction.denominator_ - fraction.numerator_ * tempFrac.denominator_;
	tempFrac.denominator_ = tempFrac.denominator_ * fraction.denominator_;
	return tempFrac.reduce();
}

Fraction& Fraction::operator-=(Fraction const& fraction) {
	numerator_ = numerator_ * fraction.denominator_ - fraction.numerator_ * denominator_;
	denominator_ = denominator_ * fraction.denominator_;
	reduce();
	return *this;
}

Fraction Fraction::operator*(Fraction const& fraction) {
	Fraction tempFrac = *this;
	if (isOverflowing(tempFrac.numerator_, fraction.numerator_) || isOverflowing(tempFrac.denominator_, fraction.denominator_))
		throw std::overflow_error("Overflow while trying to multiply fractions!");
	else {
		tempFrac.numerator_ = tempFrac.numerator_ * fraction.numerator_;
		tempFrac.denominator_ = tempFrac.denominator_ * fraction.denominator_;
		return tempFrac.reduce();
	}
}

Fraction& Fraction::operator*=(Fraction const& fraction) {
	if (isOverflowing(numerator_, fraction.numerator_) || isOverflowing(denominator_, fraction.denominator_))
		throw std::overflow_error("Overflow while trying to multiply fractions!");
	else {
		numerator_ = numerator_ * fraction.numerator_;
		denominator_ = denominator_ * fraction.denominator_;
		reduce();
		return *this;
	}
}

Fraction Fraction::operator/(Fraction const& fraction) {
	Fraction tempFrac = *this;
	if (isOverflowing(tempFrac.numerator_, fraction.denominator_) || isOverflowing(tempFrac.denominator_, fraction.numerator_))
		throw std::overflow_error("Overflow while trying to divide fractions!");
	else {
		tempFrac.numerator_ = tempFrac.numerator_ * fraction.denominator_;
		tempFrac.denominator_ = tempFrac.denominator_ * fraction.numerator_;
		return tempFrac.reduce();
	}
}

Fraction& Fraction::operator/=(Fraction const& fraction) {
	if (isOverflowing(numerator_, fraction.denominator_) || isOverflowing(denominator_, fraction.numerator_))
		throw std::overflow_error("Overflow while trying to divide fractions!");
	else {
		numerator_ = numerator_ * fraction.denominator_;
		denominator_ = denominator_ * fraction.numerator_;
		reduce();
		return *this;
	}
}

bool Fraction::isOverflowing(int a, int b) {
	return a > INT_MAX / b;
}

int Fraction::getGCD(int a, int b) {
	int h;
	while (b != 0) {
		h = a % b;
		a = b;
		b = h;
	}
	return a;
}