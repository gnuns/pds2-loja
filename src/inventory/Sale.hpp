#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <string>
#include <map>

#include "Product.hpp"
#include "user/Employee.hpp"

using namespace std;
using namespace user;

namespace inventory {
	class Sale {
	private:
        int _id;
        string _date;
        Employee*  _seller;
        map<int, int> _items;
        void saveSales();
	public:
		Sale(int id, Employee* seller, string date);
       
        void addItem(int productId, int quantity);

        int getId();
        string getDate();
        double getTotalPrice();
        Employee* getSeller();        
        
        ~Sale();
    };
}

#endif