#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <string>
#include <map>

#include "Product.hpp"
#include "user/Person.hpp"

using namespace std;
using namespace user;

namespace inventory {
	class Sale {
	private:
        int _id;
        string _date;
        Person*  _seller;
        map<int, int> _items;
        void saveSales();
        double _totalPrice;
        
	public:
		Sale(int id, Person* seller, string date);
       
        void addItem(Product* product, int quantity);

        int getId();
        string getDate();
        double getTotalPrice();
        void setTotalPrice(double);
        Person* getSeller();        
        map<int, int> getItems();
        
        ~Sale();
    };
}

#endif