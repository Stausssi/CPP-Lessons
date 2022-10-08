#include "Product.h"

int main() {
	using namespace std;
	
	/*string name;
	int year;
	double price;

	cout << "- Enter a product -" << endl << "Name: ";
	cin >> name;
	cout << "Year: ";
	cin >> year;
	cout << "Price: ";
	cin >> price;

	cout << "- Enter a product -" << endl << "Name: ";
	cin >> name;
	cout << "Year: ";
	cin >> year;
	cout << "Price: ";
	cin >> price;

	cout << "Enter the year of the cloned Product: ";
	cin >> year;

	cout << "The price of the first Product is: " << firstProduct.getPrice() << endl;
	cout << "The price of the second Product is: " << secondProduct.getPrice() << endl;
	cout << "The price of the third Product is: " << thirdProduct.getPrice() << endl;

	cout << "The difference between the first and the second price is " << firstProduct.comparePrice(secondProduct) << endl;

	cout << "The first ProductID is: " << firstProduct.getProductID() << endl;
	cout << "The second ProductID is: " << secondProduct.getProductID() << endl;
	cout << "The third ProductID is: " << thirdProduct.getProductID() << endl;

	cout << "Is the first product newer than 2020? " << firstProduct.isNewer(2020) << endl;
	cout << "Is the second product newer than 2020? " << secondProduct.isNewer(2020) << endl;
	cout << "Is the third product newer than 2020? " << thirdProduct.isNewer(2020) << endl;

	cout << "The highest price ever is " << Product::getHightestPrice() << endl;
	cout << "The lowest price ever is " << Product::getLowestPrice() << endl;*/

	Product firstProduct("Test1", 2020, 5);
	Product secondProduct("Test2", 123, 10);
	Product thirdProduct(secondProduct, 2020);
	Product fourthProduct("Test4", 2019, 19.99);
	Product fifthProduct("Test5", 2001, 123.99);
	Product sixthProduct("Test6", 1994, 99.99);

	std::vector<Product*> products;
	products.push_back(&firstProduct);
	products.push_back(&secondProduct);
	products.push_back(&thirdProduct);
	products.push_back(&fourthProduct);
	products.push_back(&fifthProduct);
	products.push_back(&sixthProduct);

	std::random_shuffle(products.begin(), products.end());
	cout << "ProductID: " << products.front()->getProductID() << endl;

	BetterPricelist list(products);
	//list.add(&firstProduct);
	//list.add(&secondProduct);
	//list.add(&thirdProduct);

	cout << "The priciest product costs " << list.getMaxPrice() << endl;
	cout << "The cheapest product costs " << list.getMinPrice() << endl;
	cout << "The average price is " << list.getAvgPrice() << endl;

	vector<Product*> yearList = list.getListFromYear(2020);
	cout << yearList.size() << " products are from 2020" << endl;

	/* 
	int in;
	cout << "To change the price of the first product press 1: ";
	cin >> in;

	if (in) {
		double newPrice;
		cout << "What is the new price? ";
		cin >> newPrice;

		firstProduct.setPrice(newPrice);

		cout << "This product now costs " << firstProduct.getPrice() << endl;
	}

	Scanner firstScanner;
	Scanner secondScanner;
	Scanner thirdScanner;

	cout << "Is the first ProductID correct? " << firstScanner.isCorrectID(firstProduct) << endl;
	cout << "Is the second ProductID correct? " << secondScanner.isCorrectID(secondProduct) << endl;
	cout << "Is the third ProductID correct? " << thirdScanner.isCorrectID(thirdProduct) << endl;

	Product products[] = { firstProduct, secondProduct, thirdProduct };

	Pricelist list(products, 3);

	cout << "The priciest product costs " << list.maxPrice() << endl;
	cout << "The cheapest product costs " << list.minPrice() << endl;
	cout << "The average price is " << list.averagePrice() << endl;
	*/

	cout << endl;
	system("pause");
}