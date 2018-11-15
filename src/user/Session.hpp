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
<<<<<<< HEAD
		Person *_person;
  public:
		string _username;
    Session();
=======
		Person _person;
	public:
>>>>>>> d6c921e63a7c89a4e4f1a8549b3935a13a630b89
    Session(string username, string password);

	};
}

#endif
