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
	/**
	 * Classe que gerencia a equipe de funcionários da loja.
	 */
	class Team {
	private:
		map<string, Person*> _people;
		void savePeople();
		void printUser(Person*);
	public:
		Team();
		Person* getPersonByUsername(string);
		void listManager();
		void listEmployees();
		void addPerson(string, string, string, bool isManager);
		void deletePerson(string username);
		void listUsers();
		~Team();
	};
}

#endif
