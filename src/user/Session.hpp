#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>
#include "Person.hpp"

using namespace std;

namespace user {
	
	class Session {
	private:
		Person *_person;
	public:
		string _username;
		Session(string, string);
	};
}

#endif
