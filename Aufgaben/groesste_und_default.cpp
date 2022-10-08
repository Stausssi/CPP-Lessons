#include <iostream>
#include <Windows.h>

/*
 * Schreiben Sie eine C++ Funktion, welche aus zwei bis vier übergebenen Zahlen die größte Zahl bestimmt und zurück liefert. 
 * Lösen Sie diese Aufgabe mit Überladung.
 * Die Funktion muss sowohl mit float, als auch mit integer Werten funktionieren (nicht gemischt).
 */

int biggest(int a, int b, int c = INT_MIN, int d = INT_MIN) {
    int max = a;

    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}

float biggest(float a, float b, float c = INT_MIN, float d = INT_MIN) {
    float max = a;
  
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}

int main() {
    using namespace std;

    cout << "The biggest number is " << biggest((float)11512.1, 6123599412312.4312, 12341.5);

    system("pause");
}