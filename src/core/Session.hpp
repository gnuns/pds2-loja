#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>

#include "../inventory/Stock.hpp"
#include "../user/Person.hpp"
#include "../user/Team.hpp"

using namespace std;
using namespace inventory;
using namespace user;

namespace core {

	class Session {
	private:
		Person* _currentUser;
		Stock* _stock;
		Team* _team;
	public:
		Session();
		Person* getCurrentUser();
		Stock* getStock();
		Team* getTeam();
		void tryToLogin(string, string);
		void setCurrentUser(Person*);
		void logout();
	};
}

#endif
