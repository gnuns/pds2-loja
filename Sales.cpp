#include "Sales.hpp"
#include "core/DataFile.hpp"

using namespace core;
using namespace std; 

void inventory::Sales::listSales() {
	// Imprime a lista de vendas
	for(auto it = _sales.begin(); it != _sales.end(); it++) {
		cout << it->first << '\t' << flush;
		cout << it->second->getId() << '\t' << flush;
		cout << it->second->getEmployeeName() << '\t' << flush;
		cout << it->second->getDate() << '\t' << flush;
		cout << it->second->getPaymentMethod() << '\t' << flush;
		cout << it->second->getPrice() << endl;
	}
}

// Adiciona uma venda a lista de vendas
void inventory::Sales::addSale(Sale* sale) {
	// Verfica, pelo ID, se do produto passado já existe
		_sales.insert (pair<int, Sale*> (sale->getId(), sale));
		saveSales();
}

// Pesquisa por determinada venda a partir do ID
void inventory::Sales::searchSaleById(int id) {
	auto it = _sales.find(id);
	cout << it->second->getId() << '\t' << flush;
	cout << it->second->getEmployeeName() << '\t' << flush;
	cout << it->second->getDate() << '\t' << flush;
	cout << it->second->getPaymentMethod() << '\t' << flush;
	cout << it->second->getPrice() << endl;
}

// Pesquisa por vendas realizadas na data
void inventory::Sales::searchSalesByDate(string date) {
	for(auto it = _sales.begin(); it != _sales.end(); it++) {
    	if(it->second->getDate() == date) {
    		cout << it->second->getId() << '\t' << flush;
			cout << it->second->getEmployeeName() << '\t' << flush;
			cout << it->second->getDate() << '\t' << flush;
			cout << it->second->getPaymentMethod() << '\t' << flush;
			cout << it->second->getPrice() << endl;
		}
	}
}

// Pesquisa por vendas com o determinado preco
void inventory::Sales::searchSalesByPrice(double price) {
	for(auto it = _sales.begin(); it != _sales.end(); it++) {
    	if(it->second->getPrice() == price) {
			cout << it->second->getId() << '\t' << flush;
			cout << it->second->getEmployeeName() << '\t' << flush;
			cout << it->second->getDate() << '\t' << flush;
			cout << it->second->getPaymentMethod() << '\t' << flush;
			cout << it->second->getPrice() << endl;
		}
	}
}