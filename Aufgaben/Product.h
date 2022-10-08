#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

class Scanner;

class Product {
public:
	Product(std::string name, int year, double price = 0);
	Product(const Product& toBeCloned, int year);
	~Product();
	void setPrice(double price);
	double getPrice() const;
	double comparePrice(Product otherProduct);
	int getYear() const { return productionyear_; }
	bool isNewer(int year);
	std::string getProductID() const;
	std::string getName() const;

	static int getLowestPrice() { return lowestPriceEver == INT_MAX ? 0 : lowestPriceEver; }
	static int getHightestPrice() { return highestPriceEver == INT_MIN ? 0 : highestPriceEver; }

private:
	int productionyear_;
	double price_;
	std::string name_;
	std::string productID_;
	void generateProductID();

	static int lowestPriceEver;
	static int highestPriceEver;
	friend class Scanner;
};

int Product::lowestPriceEver = INT_MAX;
int Product::highestPriceEver = INT_MIN;

class Scanner {
public:
	bool isCorrectID(Product const& product) const;
};

class Pricelist {
public:
	Pricelist(Product products[], unsigned int length);
	double maxPrice() const;
	double minPrice() const;
	double averagePrice() const;
private:
	Product* products_;
	unsigned int length_;
};

class BetterPricelist {
public:
	BetterPricelist(std::vector<Product*> productVector) { add(productVector); }

	void add(Product* product);
	void add(std::vector<Product*> products);

	double getMaxPrice() const { return Product::getHightestPrice(); }
	double getMinPrice() const { return Product::getLowestPrice(); }
	double getAvgPrice() const { return avg_; }

	std::vector<Product*> getListFromYear(int year) {
		std::vector<Product*> list;
		Product* tmp = products_.front();
		int count = 0;

		while (tmp != products_.back()) {
			if (tmp->getYear() == year) list.push_back(tmp);
			tmp = products_.at(count++);
		}

		return list;
	}
private:
	double sum_ = 0;
	double avg_ = 0;
	std::vector<Product*> products_;
};

void BetterPricelist::add(Product* product) {
	products_.push_back(product);
	sum_ += product->getPrice();
	avg_ = sum_ / products_.size();
}

void BetterPricelist::add(std::vector<Product*> products) {
	if (!products.empty()) {
		Product* tmp = products.front();

		for (int i = 0; tmp != products.back(); i++) {
			add(tmp);
			tmp = products.at(i);
		}
	}
}

Product::Product(std::string name, int year, double price) {
	name_ = name;
	productionyear_ = year;
	price_ = price;
	setPrice(price);
	generateProductID();
}

Product::Product(const Product& toBeCloned, int year) {
	name_ = toBeCloned.name_;
	productionyear_ = year;
	setPrice(toBeCloned.price_);
	generateProductID();
}

void Product::generateProductID() {
	productID_ = name_ + std::to_string(productionyear_);
}

std::string Product::getProductID() const {
	return productID_;
}

std::string Product::getName() const {
	return name_;
}

void Product::setPrice(double price) {
	price_ = price;

	if (price < lowestPriceEver) lowestPriceEver = price;
	if (price > highestPriceEver) highestPriceEver = price;
}

double Product::getPrice() const {
	return price_;
}

double Product::comparePrice(Product otherProduct) {
	double diff = price_ - otherProduct.price_;
	if (diff > 0)
		return diff;
	else
		return -diff;
}

bool Product::isNewer(int year) {
	return productionyear_ > year;
}


Product::~Product() {
	std::cout << std::endl << "The object with the ID " << productID_ << " was eliminated" << std::endl;
}

// Scanner
bool Scanner::isCorrectID(Product const& product) const {
	return product.getProductID() == product.getName() + std::to_string(product.productionyear_);
}

// Pricelist
Pricelist::Pricelist(Product products[], unsigned int length) {
	products_ = products;
	length_ = length;
}

double Pricelist::maxPrice() const {
	double max = 0;
	for (int i = 0; i < length_; i++) {
		if (products_[i].getPrice() > max) max = products_[i].getPrice();
	}

	return max;
}

double Pricelist::minPrice() const {
	double min = DBL_MAX;
	for (int i = 0; i < length_; i++) {
		if (products_[i].getPrice() < min) min = products_[i].getPrice();
	}
	return min;
}

double Pricelist::averagePrice() const {
	double sum_ = 0;
	for (int i = 0; i < length_; i++) sum_ += products_[i].getPrice();
	return sum_ / length_;
}

// Better Pricelist
