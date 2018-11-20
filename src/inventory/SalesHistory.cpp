#include "SalesHistory.hpp"
#include "core/DataFile.hpp"

using namespace core;
using namespace std; 

inventory::SalesHistory::SalesHistory() {
	// ---
}

void inventory::SalesHistory::saveSalesHistory() {
	// ---
}

void inventory::SalesHistory::listSales() {
	for (auto it = _sales.begin(); it != _sales.end(); it++) {
		cout << it->first << '\t' << flush;
		printSale(it->second);
	}
}

void inventory::SalesHistory::addSale(Sale* sale) {
		_sales.insert (pair<int, Sale*> (sale->getId(), sale));
		saveSalesHistory();
}


void inventory::SalesHistory::searchSaleById(int id) {
	auto it = _sales.find(id);

  if (it == _sales.end()) return;
  printSale(_sales[id]);
}

// Pesquisa por vendas realizadas na data
void inventory::SalesHistory::searchSalesByDate(string date) {
	for (auto it = _sales.begin(); it != _sales.end(); it++) {
		if (it->second->getDate() == date) {
			 printSale(it->second);
		}
	}
}

// TODO: Mover para classe Sale
void inventory::SalesHistory::printSale(Sale* sale) {
		cout << "#" << sale->getId() << '\t' << flush;
		cout << sale->getSeller()->getName() << '\t' << flush;
		cout << sale->getDate() << '\t' << flush;
		cout << sale->getTotalPrice() << endl;
}

inventory::SalesHistory::~SalesHistory() {}

