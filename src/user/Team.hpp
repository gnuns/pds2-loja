#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <map>

#include "Manager.hpp"
#include "Employee.hpp"
#include "Person.hpp"

using namespace std;

namespace user {
	class Team {
	private:
		map<string, Person*> _people;
	public:
		Team ();
		void listManager();
		void listEmployees();
		void removePerson(string);
		void addPerson(string, string, string, bool isManager);
		Person* getPersonByUsername(string);
	};
}

#endif
