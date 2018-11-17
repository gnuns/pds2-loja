#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace inventory {
	class Product {
		private:
			int _id;
			string _name;
			string _description;
			int _quantity;
			string _provider;
			double _price;
		public:
			Product(int, string, string, int, string, double);

			int getId();
			string getName();
			string getDescription();
			int getQuantity();
			string getProvider();
			double getPrice();
			void setId(int);
			void setName(string);
			void setDescription(string);
			void setQuantity(int);
			void setProvider(string);
			void setPrice(double);
			void save();

			~Product();
	};
}

#endif
