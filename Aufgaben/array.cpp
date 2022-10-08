#include <iostream>
#include <Windows.h>

/*
 * Schreiben Sie ein C++ Programm in welchem innerhalb einer Schleife neun Ganzzahlen eingegeben werden müssen.
 * Diese werden in einem 3*3 Array gespeichert und formatiert in 3er Zeilen wieder an den Bildschirm ausgegeben.
 * Verwenden Sie für die Ausgabe eine for-Schleife (oder mehrere).
 */

int main() {
	using namespace std;

	int numbers[3][3];

	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			cout << "Enter a number: ";
			cin >> numbers[i][x];
		}
	}


	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			cout << numbers[i][x];
		}
		cout << endl;
	}

	system("pause");
}