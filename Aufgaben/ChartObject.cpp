#include "ChartObject.h"

using namespace std;

unsigned int ChartObject::instanceCount = 0;
unsigned int Circle::instanceCount = 0;

int main() {
	try {
		vector<ChartObject*> graphicObjects;

		Point point(10, 10);
		Line line(11, 11, 11, 12);
		Circle circle(12, 12, 5);
		//Rectangle rect(13, 13, 15, 15);

		graphicObjects.push_back(&point);
		graphicObjects.push_back(&line);
		graphicObjects.push_back(&circle);

		for (int i = 0; i < graphicObjects.size(); i++) cout << graphicObjects.at(i)->draw() << endl;

		//cout << point.draw() << endl;
		//cout << line.draw() << endl;
		//cout << circle.draw() << endl;
		//cout << rect.draw() << endl;

		cout << endl << "There are " << ChartObject::getInstanceCount() << " ChartObjects!" << endl;
		cout << Circle::getInstanceCount() << " of them are circles!" << endl;
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what() << endl;
	}

	cout << endl;
	system("pause");
}