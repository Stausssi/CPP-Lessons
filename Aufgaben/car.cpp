#include "Car.h"
#include <iostream>
#include <Windows.h>

int main() {
	using namespace std;

	Car automobil(10, 100);
	unsigned int in;

	do {
		system("cls");

		do {
			cout << "Drive (0) or refuel (1) or exit (2)? ";
			cin >> in;
		} while (in > 2);

		if (in == 0) {
			double distance;

			do {
				cout << "What's the distance to your destination? ";
				cin >> distance;
			} while (distance <= 0);

			double remaining = automobil.drive(distance);

			if (remaining < 0) {
				cout << "The tank filling can't cover the entire distance!";
			}
			else {
				cout << "You have " << remaining << "l left in your tank";
			}
		}
		else if (in == 1) {
			double amount;

			do {
				cout << "How much would you like to refill? ";
				cin >> amount;
			} while (amount <= 0);

			double response = automobil.refuel(amount);

			if (response > 0) {
				cout << "Successfully refueled! You now have " << response << "l in your tank.";
			}
			else {
				cout << -response << "l couldn't be filled into the tank!";
			}
		}

		cout << endl;
		system("pause");
	} while (in < 2);
}