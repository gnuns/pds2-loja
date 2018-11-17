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
		map<int, Product> products;
		void saveProducts();
	public:
		void listProducts();
		void loadProducts();
		void removeProduct(int);
		void addProduct(Product*);
		void searchProductById(int);
		void searchProductByName(string);
	};
}

#endif
