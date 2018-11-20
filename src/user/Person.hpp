#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

#include "../core/DataFile.hpp"

using namespace std;
using namespace core;

namespace user {

	class Person {
	private:
		string _name;
		string _username;
		string _password;
	protected:
		string getPassword();
	public:
		Person(string, string, string);

		string getName();
		string getUsername();
		void setPassword(string password);
		void setName(string name);
		void setUserame(string username);
		bool checkPassword(string password);
		void savePerson();
		virtual const bool isManager() = 0;

		~Person();
	};
}

#endif
