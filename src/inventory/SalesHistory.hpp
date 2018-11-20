#ifndef SALESHISTORY_H
#define SALESHISTORY_H

#include <iostream>
#include <string>
#include <map>

#include "Sale.hpp"
#include "../core/Session.hpp"
 
using namespace std;
using namespace core;

namespace inventory {
	class SalesHistory {
	private:
		map<int, Sale*> _sales;
		void saveSalesHistory();
		void printSale(Sale*);
	public:
		SalesHistory(Session* session);
		map<int, Sale*> getSales();
		void listSales();
		void addSale(Sale*, Session*);
        void cancelSale(int id);
		void searchSaleById(int);
        void searchSalesByDate(string date);
        void searchSalesByEmployee(int id);
        void searchSalesByPrice(double);
        ~SalesHistory();
    };
}

#endif
