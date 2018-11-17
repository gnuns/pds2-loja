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
			double _price;
		public:
			Product(int, string, string, double);

			int getId();
			string getName();
			string getDescription();
			double getPrice();
			void setId(int id);
			void setName(string name);
			void setDescription(string description);
			void setPrice(double price);
			void save();

			~Product();
	};
}

#endif