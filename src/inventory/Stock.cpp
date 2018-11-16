#include "Stock.hpp"

void inventory::Stock::listProducts() {
	for(map<int, Product> :: iterator it = products.begin(); it != products.end(); it++) {
		cout << it->first << it->second->getName() << '\t' << flush;
		cout << it->second->getDescription() << '\t' << flush;
		cout << it->second->getQuantity() << '\t' << flush;
		cout << it->second->getProvider() << '\t' << flush;
		cout << it->second->getPrice() << endl;
	}
}

void inventory::Stock::loadProducts() {
	//Fazer uma função para pegar os dados do txt e jogar no map
}

void inventory::Stock::removeProduct(int id) {
	products.erase(id);
	saveProducts();
}

void inventory::Stock::saveProducts() {
	//Fazer uma função para pegar os dados do map e jogar no txt
}

void inventory::Stock::addProduct(Product* product) {
	if(products.find(product->getId()) == products.end()) {
		products.insert (pair<int, Product> (product->getId(), *product));
		saveProducts();
	}else{
		cout << "Produto ja existe" << endl;
	}
	
}

void inventory::Stock::searchProductById(id) {
	map<int, Product>::iterator it;
	it = products.find(id);
	cout << it->second->getId() << '\t' << flush;
	cout << it->second->getName() << '\t' << flush;
	cout << it->second->getDescription() << '\t' << flush;
	cout << it->second->getQuantity() << '\t' << flush;
	cout << it->second->getProvider() << '\t' << flush;
	cout << it->second->getPrice() << endl;
}

void inventory::Stock::searchProductByName(name) {
	map<int, Product>::iterator it;
	it = products.find(name);
	cout << it->second->getId() << '\t' << flush;
	cout << it->second->getName() << '\t' << flush;
	cout << it->second->getDescription() << '\t' << flush;
	cout << it->second->getQuantity() << '\t' << flush;
	cout << it->second->getProvider() << '\t' << flush;
	cout << it->second->getPrice() << endl;
}