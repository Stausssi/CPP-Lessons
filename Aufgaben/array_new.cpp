#include <iostream>
#include <Windows.h>

/*
 * Schreiben Sie ein C++ Programm, in dem der Nutzer zuerst eingeben darf, wie viele Zahlenwerte er dynamisch anlegen
 * moechte und dann diese Zahlenwerte (in einer Schleife) eingibt.
 * Die Werte sollen dabei dynamisch mit new angelegt werden. Verketten Sie diese Werte nicht,
 * sondern legen Sie einen (statischen) Index-Array an, der die Zeiger auf die Zahlen speichert.
 * Die Maximalzahl an Werten, die der Nutzer eingeben darf, ist fuenf.
 * Geben Sie abschließend die Werte wieder aus und geben Sie danach den Speicher wieder frei.
 */

int main() {
	using namespace std;

	int count;
	do {
		cout << "How many integers should the array contain? ";
		cin >> count;
	} while (count > 5);

	int* numbers = new int[count];

	for (int i = 0; i < count; i++) {
		cout << "Enter a number: ";
		cin >> numbers[i];
	}

	for (int i = 0; i < count; i++) 
		cout << numbers[i] << ", ";

	cout << endl;
	system("pause");
}
