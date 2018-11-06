#include "Person.hpp"

Person::Person(string name, string username, string password) : 
_name(name), _username(username), _password(password) {}

string Person::getName() {
	return _name;
}

string Person::getUsername() {
	return _username;
}

void Person::setName(string name) {
	_name = name;
}

void Person::setUserame(string username) {
	_username = username;
}

void Person::setPassword(string password) {
	_password = password;
}

bool Person::checkPassword(string password) {
	if (password == _password) {
		return true;
	}

	return false;
}
