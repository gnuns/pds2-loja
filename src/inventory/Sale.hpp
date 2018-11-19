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
        int _id;
        int _idFuncionario;
        string _date;
        string _paymentMethod;
        double _price;
        map <int productId, int quantity> _itensVenda; // armazena o id e a quantidade do produto na venda
	public:
		Sale(int, int, string, string, double, map);
       
        void addItem(int productId, int quantity);
        void removeItem(int productId);

        void setId(int);
        void setIdEmployee(int);
        void setDate(string);
        void setPaymentMethod(string);
        void setPrice(double);

        int getId();
       
        string getDate();
        string getPaymentMethod();
        double getPrice();

        int getIdEmployee();
        string getEmplyeeName();
        
        ~Sale();
    };
}

#endif