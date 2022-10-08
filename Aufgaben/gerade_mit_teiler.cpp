#include <iostream>
#include <Windows.h>

/*
 * Schreiben Sie eine C++ Funktion, welche aus zwei bis vier übergebenen Zahlen die größte Zahl bestimmt und zurück liefert. 
 * Lösen Sie diese Aufgabe mit Überladung.
 * Die Funktion muss sowohl mit float, als auch mit integer Werten funktionieren (nicht gemischt).
 */

int main() {
	using namespace std;

    float numbers[4] = { 0 };
    int i = 0;

    do {
        cout << "Enter a number (exit with 0): ";
        cin >> numbers[i];
    } while (numbers[i] != 0 && i++ < 3);

    i = 0;
    while (numbers[i] != 0 && i < 4) {

    }
	system("pause");
}

float biggest(int a, int b) {

}

float biggest(int a, int b, int c) {

}

float biggest(int a, int b, int c, int d) {

}

float biggest(float a, float b) {

}

float biggest(float a, float b, float c) {

}

float biggest(float a, float b, float c, float d) {

}