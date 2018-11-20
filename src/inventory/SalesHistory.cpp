#include "SalesHistory.hpp"
#include "core/DataFile.hpp"

using namespace core;
using namespace std; 

inventory::SalesHistory::SalesHistory(Session* session) {
 	// Lê o arquivo com a lista de ids das vendas
  	DataFile* saleList = new DataFile("./data/saleshistory.idx.data");
	  DataFile* currentSaleData;
	 
    for (auto it : saleList->getParametersMap()) {
    if (it.first.empty()) continue;
    // Lê o arqvuivo individual com os dados da venda
    currentSaleData = new DataFile((string)"./data/saleshistory/" + (string)it.first + (string)".data");
	  
	 //cout << session->getTeam()->getPersonByUsername(currentSaleData->getParam("seller"))->getName();
	  _sales[stoi(it.first)] = new Sale(
      stoi(currentSaleData->getParam("id")),
      session->getTeam()->getPersonByUsername(currentSaleData->getParam("seller")),
      currentSaleData->getParam("date")
    );
  
	}
}

void inventory::SalesHistory::saveSalesHistory() {
		// Salva a lista de vendas no arquivo
	DataFile* salesList = new DataFile("./data/saleshistory.idx.data", false);
	DataFile* currentSaleData;
	map<int, int> items;
	int i = 0;
  for(auto it = _sales.begin(); it != _sales.end(); it++) {

    salesList->setParam(to_string(it->second->getId()));
    currentSaleData = new DataFile((string)"./data/saleshistory/" + to_string(it->second->getId()) + (string)".data", false);
	currentSaleData->setParam("id", to_string(it->second->getId()));
		currentSaleData->setParam("seller",  it->second->getSeller()->getUsername());
	currentSaleData->setParam("totalPrice", to_string(it->second->getTotalPrice()));
	items =  it->second->getItems();
	for(auto x = items.begin(); x !=  items.end(); x++) {
		currentSaleData->setParam(to_string(i), to_string(x->first) + "x" + to_string(x->second));
		i++;
	}
	currentSaleData->save();
}
  salesList->save();
}

map<int, Sale*> inventory::SalesHistory::getSales(){
	return _sales;
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

