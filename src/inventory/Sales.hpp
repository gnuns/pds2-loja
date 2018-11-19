#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <string>
#include <map>

#include "Sale.hpp"
 
using namespace std;

namespace inventory {
	class Sales {
	private:
		map<int, Sale*> _sales;
		void saveSales();
	public:
		Sales();
		void listSales();
		void addSale(Sale*);
        void cancelSale(int); // passar o id 
		void searchSaleById(int);
        void searchSalesByDate(string date);
        void searchSalesByEmployee(int); // passar o id
        void searchSalesByPrice(double);
    };
}

#endif
