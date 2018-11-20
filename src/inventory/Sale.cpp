#include "Sale.hpp"

inventory::Sale::Sale(int id, Person* seller, string date) :
	_id(id), _seller(seller), _date(date) {
		_totalPrice = 0.0;
	}

int inventory::Sale::getId() {
	return _id;
}

string inventory::Sale::getDate(){
	return _date;
}
void inventory::Sale::setTotalPrice(double totalPrice){
	_totalPrice = totalPrice;
}
double inventory::Sale::getTotalPrice(){
/*	for(auto it = _items.begin(); it != _items.end(); it++) {
        cout << session->getStock()->getProductById(it->first)->getName() 
        << " x " << it->second; 
    }*/
	return _totalPrice;
}

Person* inventory::Sale::getSeller(){
	return _seller;
}

void inventory::Sale::addItem(Product* product, int quantity){
    _items.insert (pair<int, int> (product->getId(), quantity));
	_totalPrice += product->getPrice() * quantity;
}

map<int, int> inventory::Sale::getItems(){
	return _items;
}

inventory::Sale::~Sale() {}
