#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#include <stdexcept>

#define _USE_MATH_DEFINES
#include <math.h>

class Area {
public:
	virtual double getArea() = 0;
	virtual double getCircumference() = 0;
private:
	double areasize_;
	double circumference_;
};

class ChartObject {
public:
	ChartObject(int coordX, int coordY) : coordX_(coordX), coordY_(coordY) { instanceCount++; }
	~ChartObject() { instanceCount--; }

	virtual std::string draw() = 0;
	static unsigned int getInstanceCount() { return instanceCount; }

protected:
	//virtual std::string getForm() const = 0;
	//virtual std::string getExtra() = 0;

	int coordX_;
	int coordY_;

private:
	static unsigned int instanceCount;
};

class Point : public ChartObject {
public:
	Point(int coordX, int coordY) : ChartObject(coordX, coordY) {}

	std::string draw() override { return std::to_string(coordX_) + ", " + std::to_string(coordY_) + ": Point"; }

protected:
	//std::string getForm() const override { return "Point"; }
	//std::string getExtra() override { return ""; }
};

class Line : public ChartObject {
public:
	Line(int coordX, int coordY, int endX, int endY) : ChartObject(coordX, coordY), endX_(endX), endY_(endY) {
		if (coordX == endX && coordY == endY) throw std::invalid_argument("Can't create a line with the length 0");
	}

	std::string draw() override { return std::to_string(coordX_) + ", " + std::to_string(coordY_) + ": Line -> endX=" + std::to_string(endX_) + ", endY=" + std::to_string(endY_); }

private:
	//std::string getForm() const override { return "Line"; }
	//std::string getExtra() override { return ": endX=" + std::to_string(endX_) + ", endY=" + std::to_string(endY_); }

	int endX_;
	int endY_;
};

class Circle : public ChartObject, public Area {
public:
	Circle(int coordX, int coordY, double radius) : ChartObject(coordX, coordY), radius_(radius) {
		if (radius < 0)	throw std::invalid_argument("Can't create a circle with a negative radius!");
		Circle::instanceCount++;
	}
	~Circle() { Circle::instanceCount--; }

	std::string draw() override { return std::to_string(coordX_) + ", " + std::to_string(coordY_) + ": Circle -> Radius=" + std::to_string(radius_); }
	
	double getArea() override { return M_PI * pow(radius_, 2); }
	double getCircumference() override { return 2 * M_PI * radius_; }

	static unsigned int getInstanceCount() { return instanceCount; }
private:
	//std::string getForm() const override { return "Circle"; }
	//std::string getExtra() override { return ": Radius=" + std::to_string(radius_); }

	double radius_;

	static unsigned int instanceCount;
};

class Rectangle : public ChartObject, public Area {
public:
	Rectangle(int coordX, int coordY, int cornerX, int cornerY) : ChartObject(coordX, coordY), cornerX_(cornerX), cornerY_(cornerY) {
		if (coordX == cornerX || coordY == cornerY)	throw std::invalid_argument("Can't create a rectangle with the area 0!");
	}

	std::string draw() override { return std::to_string(coordX_) + ", " + std::to_string(coordY_) + ": Rectangle -> cornerX=" + std::to_string(cornerX_) + ", cornerY=" + std::to_string(cornerY_); }

	double getArea() override { return abs((coordX_ - cornerX_) * (coordY_ - cornerY_)); }
	double getCircumference() override { return 2 * abs(coordX_ - cornerX_) + 2 * abs(coordY_ - cornerY_); }
private:
	//std::string getForm() const override { return "Rectangle"; }
	//std::string getExtra() override { return ": cornerX=" + std::to_string(cornerX_) + ", cornerY=" + std::to_string(cornerY_); }

	int cornerX_;
	int cornerY_;
};