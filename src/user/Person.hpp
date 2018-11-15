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
		void setPassword(string password);
	public:
		Person(string name, string username, string password);

		string getName();
		string getUsername();
		void setName(string name);
		void setUserame(string username);
		bool checkPassword(string password);

		~Person();
	};
}

#endif
