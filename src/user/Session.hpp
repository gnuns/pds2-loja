#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>

#include "Person.hpp"

using namespace std;
using namespace user;

namespace user {

	class Session {
	private:
		Person *_person;
  public:
		string _username;
    Session();
    Session(string username, string password);

	};
}

#endif
