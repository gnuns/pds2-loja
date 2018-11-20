#include "Stock.hpp"
#include "../core/DataFile.hpp"

using namespace core;
using namespace std;
 
void inventory::Stock::listProducts() {
	// Imprime a lista de produtos (carregada no construtor)

	cout << endl;
	cout  << '\t' << flush << "-------------------- Estoque --------------------" << endl;
	cout << endl;
	int quantity;
	string status;

	for(auto it = _products.begin(); it != _products.end(); it++) {
	    quantity = (it->second->getQuantity());
		if(quantity > 0){
			status = " unidades (Disponível)";
		}else{
			status = " unidades (Indisponível)";
		}
     	cout << "#" << it->first << '\t' << flush;
		cout << it->second->getName() << '\t' << flush;
		cout << it->second->getDescription() << '\t' << flush;
		cout << it->second->getProvider() << '\t' << flush;
		cout << "R$ " << it->second->getPrice() << '\t' << flush;
		cout << it->second->getQuantity() << status  << endl;
	}
}

inventory::Stock::Stock() {
  	// Lê o arquivo com a lista de ids dos produtos
	DataFile* productList = new DataFile("./data/products.idx.data");
	DataFile* currentProductData;

  for (auto it : productList->getParametersMap()) {
    if (it.first.empty()) continue;
    // Lê o arqvuivo individual com os dados do produto
    currentProductData = new DataFile((string)"./data/products/" + (string)it.first + (string)".data");

    _products[stoi(it.first)] = new Product(
      stoi(it.first),
      currentProductData->getParam("name"),
      currentProductData->getParam("description"),
      stoi(currentProductData->getParam("quantity")),
      currentProductData->getParam("provider"),
      stod(currentProductData->getParam("price"))
    );
  }
}

inventory::Product* inventory::Stock::getProductById(int id){
	auto it = _products.find(id);
	return it->second;
}


void inventory::Stock::removeProduct(int id) {
	// Remove um produto a partir do parâmetro id
/*	if (it != _people.end()) {
    	_products.erase(id);
		saveProducts();
  	} else {
  		cout << "Produto não encontrado" << endl;
  	}*/
}

void inventory::Stock::saveProducts() {
	// Salva a lista de produtos no arquivo
	DataFile* productList = new DataFile("./data/products.idx.data", false);
	DataFile* currentProductData;

  for(auto it = _products.begin(); it != _products.end(); it++) {
    productList->setParam(to_string(it->second->getId()));

    currentProductData = new DataFile((string)"./data/products/" + to_string(it->second->getId()) + (string)".data", false);
    currentProductData->setParam("id", to_string(it->second->getId()));
    currentProductData->setParam("name", it->second->getName());
    currentProductData->setParam("description", it->second->getDescription());
    currentProductData->setParam("quantity", to_string(it->second->getQuantity()));
    currentProductData->setParam("provider", it->second->getProvider());
    currentProductData->setParam("price", to_string(it->second->getPrice()));
		currentProductData->save();
	}
  productList->save();
}

// Adiciona um produto ao estoque
void inventory::Stock::addProduct(Product* product) {
	// Verfica, pelo ID, se do produto passado já existe
	if(_products.find(product->getId()) == _products.end()) {
		_products.insert (pair<int, Product*> (product->getId(), product));
		saveProducts();
	} else {
		cout << "Produto ja existe" << endl;
	}
}

// Pesquisa por determinado produto a partir do ID
void inventory::Stock::searchProductById(int id) {
	auto it = _products.find(id);
	cout << it->second->getId() << '\t' << flush;
	cout << it->second->getName() << '\t' << flush;
	cout << it->second->getDescription() << '\t' << flush;
	cout << it->second->getQuantity() << '\t' << flush;
	cout << it->second->getProvider() << '\t' << flush;
	cout << it->second->getPrice() << endl;
}
// Pesquisa por determinado produto a partir do nome
void inventory::Stock::searchProductByName(string name) {
	for(auto it = _products.begin(); it != _products.end(); it++) {
    	if(it->second->getName() == name) {
    		cout << it->second->getId() << '\t' << flush;
			cout << it->second->getName() << '\t' << flush;
			cout << it->second->getDescription() << '\t' << flush;
			cout << it->second->getQuantity() << '\t' << flush;
			cout << it->second->getProvider() << '\t' << flush;
			cout << it->second->getPrice() << endl;
		}
	}
}


