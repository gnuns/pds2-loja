#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

namespace user {

	class Person {
	private:
		string _name;
		string _username;
		string _password;
	public:
		Person(string, string, string);

		string getName();
		string getUsername();
		string getPassword();
		void setPassword(string password);
		void setName(string name);
		void setUserame(string username);
		bool checkPassword(string password);
		virtual const bool isManager() = 0;

		~Person();
	};
}

#endif
