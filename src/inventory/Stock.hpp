#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

using namespace std;

namespace inventory {
	class Stock {
	private:
		map<int, Product> products;
		void saveProducts();
	public:
		void listProducts();
		void loadProducts();
		void removeProduct(int id);
		void addProduct(Product* product);
		void searchProductById(id);
		void searchProductByName(name);
	}
}

#endif