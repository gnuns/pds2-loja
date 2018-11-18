#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <string>
#include <map>

#include "Product.hpp"

using namespace std;

namespace inventory {
	class Sale {
	private:
        int _id,
        int _idFuncionario,
        string _date,
        string _paymentMethod,
        double _price,
	public:
		Sale(int, int, string, string, double);
        void setId(int);
        void setIdFuncionario(int);
        void setDate(string);
        void setPaymentMethod(string);
        void setPrice(double);
        ~Sale();
    };
}

#endif