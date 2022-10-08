#include "Fraction.h"

int main() {
	using namespace std;

	int numerator, denominator;

	cout << "Enter the numerator: ";
	cin >> numerator;

	cout << "Enter the denominator: ";
	cin >> denominator;

	try {
		Fraction fraction(numerator, denominator);
		cout << "The Fraction is " << fraction.getFraction() << endl;

		Fraction otherFraction(10);

		cout << endl;

		cout << "-- Addition --" << endl;
		Fraction equals = fraction + otherFraction;
		cout << fraction.getFraction() << " + " << otherFraction.getFraction() << " = " << equals.getFraction() << " Double: " << equals.toDouble() << endl;

		cout << equals.getFraction() << " + " << fraction.getFraction() << " = ";
		equals += fraction;
		cout << equals.getFraction() << " Double: " << equals.toDouble() << endl;

		cout << endl;

		cout << "-- Subtraction --" << endl;
		equals = fraction - otherFraction;
		cout << fraction.getFraction() << " - " << otherFraction.getFraction() << " = " << equals.getFraction() << " Double: " << equals.toDouble() << endl;

		cout << equals.getFraction() << " - " << fraction.getFraction() << " = ";
		equals -= fraction;
		cout << equals.getFraction() << " Double: " << equals.toDouble() << endl;

		cout << endl;

		cout << "-- Multiplication --" << endl;
		try {
			equals = fraction * otherFraction;
			cout << fraction.getFraction() << " * " << otherFraction.getFraction() << " = " << equals.getFraction() << " Double: " << equals.toDouble() << endl;
		}
		catch (std::overflow_error e) {
			std::cerr << e.what() << endl;
		}

		try {
			cout << equals.getFraction() << " * " << fraction.getFraction() << " = ";
			equals *= fraction;
			cout << equals.getFraction() << " Double: " << equals.toDouble() << endl;
		}
		catch (std::overflow_error e) {
			std::cerr << e.what() << endl;
		}

		cout << endl;

		cout << "-- Division --" << endl;

		try {
			equals = fraction / otherFraction;
			cout << fraction.getFraction() << " / " << otherFraction.getFraction() << " = " << equals.getFraction() << " Double: " << equals.toDouble() << endl;
		}
		catch (std::overflow_error e) {
			std::cerr << e.what() << endl;
		}

		try {
			cout << equals.getFraction() << " / " << fraction.getFraction() << " = ";
			equals /= fraction;
			cout << equals.getFraction() << " Double: " << equals.toDouble() << endl;
		}
		catch (std::overflow_error e) {
			std::cerr << e.what() << endl;
		}
	}
	catch (std::invalid_argument e) {
		cerr << e.what() << endl;
	}


	cout << endl;
	system("pause");
}