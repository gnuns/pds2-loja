#include "Product.hpp"

inventory::Product::Product(int id, string name, string description, int quantity, string provider, int price) : 
_id(id), _name(name), _description(description), _quantity(quantity), _provider(provider), _price(price) {}

int inventory::Product::getId() {
	return _id;
}

string inventory::Product::getName() {
	return _name;
}

string inventory::Product::getDescription() {
	return _description;
}

int inventory::Product::getQuantity() {
	return _quantity;
}

string inventory::Product::getProvider() {
	return _provider;
}

int inventory::Product::getPrice() {
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

void inventory::Product::setQuantity(int quantity) {
	_quantity = quantity;
}

void inventory::Product::setProvider(string provider) {
	_provider = provider
}

void inventory::Product::setPrice(int price) {
	_price = price;
}

void inventory::Product::save() {
	//Fazer função para salvar os produtos num arquivo txt
}

inventory::Product::~Product() {}