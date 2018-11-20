#include "Sale.hpp"

inventory::Sale::Sale(int id, Employee* seller, string date) :
	_id(id), _seller(seller), _date(date) {}

int inventory::Sale::getId() {
	return _id;
}

string inventory::Sale::getDate(){
	return _date;
}

double inventory::Sale::getTotalPrice(){
	// return para cada produto -> quant * preco
	return 0.0;
}

Employee* inventory::Sale::getSeller(){
	return _seller;
}

void inventory::Sale::addItem(int productId, int quantity){
	// add item id quant
}
