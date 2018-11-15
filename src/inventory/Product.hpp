#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

namespace inventory {
	class Product {
		private:
			int _id;
			string _name;
			string _description;
			int _quantity;
			string _provider;
			int _price;
		public:
			Product(int id, string name, string description, int quantity, string provider, int price);

			int getId();
			string getName();
			string getDescription();
			int getQuantity();
			string getProvider();
			int getPrice();
			void setId(int id);
			void setName(string name);
			void setDescription(string description);
			void setQuantity(int quantity);
			void setProvider(string provider);
			void setPrice(int price);
			void save();

			~Product();
	}
}

#endif