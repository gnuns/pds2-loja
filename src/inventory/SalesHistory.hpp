#ifndef SALESHISTORY_H
#define SALESHISTORY_H

#include <iostream>
#include <string>
#include <map>

#include "Sale.hpp"
 
using namespace std;

namespace inventory {
	class SalesHistory {
	private:
		map<int, Sale*> _sales;
		void saveSales();
	public:
		SalesHistory();

		void listSales();
		void addSale(Sale*);
        void cancelSale(int id);
		void searchSaleById(int);
        void searchSalesByDate(string date);
        void searchSalesByEmployee(int id);
        void searchSalesByPrice(double);

        ~SalesHistory();
    };
}

#endif
