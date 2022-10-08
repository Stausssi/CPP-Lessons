#include "templates.h"

using std::cout;
using std::endl;

int main() {
	cout << "Int to String: " << toString(7) << endl;
	cout << "Float to String: " << toString((float)7.125) << endl;
	cout << "Double to String: " << toString(7.25) << endl;

	cout << endl;

	ThreeValues<double> threeValues(1.1, 1.2, 1.3);
	cout << "Sum: " << threeValues.calculateSum() << endl;
	cout << "Min: " << threeValues.minValue() << endl;
	cout << "Max: " << threeValues.maxValue() << endl;

	cout << endl;
	system("pause");
}