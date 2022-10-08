#pragma once

class Car
{
public:
	Car(double consumption, double tankSize, double mileage = 0, double tankFilling = 100);
	double drive(double distance);
	double refuel(double volume);

private:
	double mileage_;
	double tankFilling_;
	double tankSize_;
	double consumptionPer100Km_;
};

Car::Car(double consumption, double tankSize, double mileage, double tankFilling) {
	consumptionPer100Km_ = consumption;
	tankSize_ = tankSize;
	mileage_ = mileage;
	tankFilling_ = tankFilling;
}

double Car::drive(double distance) {
	mileage_ += distance;

	if (tankFilling_ - (distance / 100) * consumptionPer100Km_ >= 0) {
		tankFilling_ -= (distance / 100) * consumptionPer100Km_;
		return tankFilling_;
	}
	else
		return -1;
}

double Car::refuel(double volume) {
	tankFilling_ += volume;

	if (tankFilling_ > tankSize_) {
		int diff = tankFilling_ - tankSize_;
		tankFilling_ -= diff;
		return -diff;
	}
	return tankFilling_;
}