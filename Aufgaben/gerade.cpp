#include <iostream>
#include <Windows.h>

int main() {
	using namespace std;
	int nr;
	bool isEven;

	cout << "Gebe eine Zahl ein: " << endl;
	cin >> nr;

	nr % 2 == 0 ? isEven = true : isEven = false;

	if (isEven) {
		cout << "Die Zahl ist gerade!" << endl;

		unsigned int dividedBy = 0;

		if (nr % 10 == 0) dividedBy = 10;
		if (nr % 100 == 0) dividedBy = 100;
		if (nr % 1000 == 0) dividedBy = 1000;

		switch (dividedBy) { 
		case 1000: 
			cout << "Die Zahl ist durch 10, 100 und 1000 teilbar!" << endl;
			break;
		case 100: 
			cout << "Die Zahl ist durch 10 und 100 teilbar!" << endl;
			break;
		case 10:
			cout << "Die Zahl ist durch 10 teilbar!" << endl;
			break;
		}
	}
	else
		cout << "Die Zahl ist ungerade und lässt sich nicht durch 10, 100 und 1000 teilen!" << endl;

	system("pause");
}