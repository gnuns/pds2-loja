#ifndef STOCK_H
#define STOCK_H
 
#include <iostream>
#include <string>
#include <map>

#include "Product.hpp"

using namespace std;

namespace inventory {
	class Stock {
	private:
		map<int, Product*> _products;
		void saveProducts();
	public:
		Stock();
		void listProducts();
		void removeProduct(int);
		void addProduct(Product*);
		void searchProductById(int);
		void searchProductByName(string);
		Product* getProductById(int);
	};
}

#endif
