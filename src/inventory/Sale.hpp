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
        Person* _seller;
        string _date;
        string _paymentMethod;
        double _price;
	public:
		Sale(int, int, string, string, double);
        void setId(int);
        void setSeller(Person*);
        void setDate(string);
        void setPaymentMethod(string);
        void setPrice(double);
        ~Sale();
    };
}

#endif