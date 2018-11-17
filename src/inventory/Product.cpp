#include "Product.hpp"

FILE* openArchiveProduct(char option);
void closeArchiveProduct(FILE *arch);

inventory::Product::Product(int id, string name, string description, double price) : 
_id(id), _name(name), _description(description), _price(price) { }

int inventory::Product::getId() {
	return _id;
}

string inventory::Product::getName() {
	return _name;
}

string inventory::Product::getDescription() {
	return _description;
}

double inventory::Product::getPrice() {
	return _price;
}

void inventory::Product::setId(int id) {
	_id = id;
}

void inventory::Product::setName(string name) {
	_name = name;
}

void inventory::Product::setDescription(string description) {
	_description = description;
}

void inventory::Product::setPrice(double price) {
	_price = price;
}

void inventory::Product::save() {

	ofstream arch;
    arch.open ("./inventory/products.txt", ios::app);
    arch << getId() << ";" << getName() << ";" << getDescription() << ";" << getPrice() << endl;
    arch.close();
}

inventory::Product::~Product() {}