#include "Person.hpp"

user::Person::Person(string name, string username, string password) :
_name(name), _username(username), _password(password) {}

string user::Person::getName() {
	return _name;
}

string user::Person::getUsername() {
	return _username;
}

string user::Person::getPassword() {
	return _password;
}

void user::Person::setName(string name) {
	_name = name;
}

void user::Person::setUserame(string username) {
	_username = username;
}

void user::Person::setPassword(string password) {
	_password = password;
}

bool user::Person::checkPassword(string password) {
	return password == _password;
}

void user::Person::savePerson(){
	DataFile* currentManagerData;
	currentManagerData = new DataFile((string)"./data/team/" + getUsername() + (string)".data", false);
	currentManagerData->setParam("username", getUsername());
	currentManagerData->setParam("name",  getName());
	currentManagerData->setParam("password", getPassword());
	
	currentManagerData->save();
}

user::Person::~Person() {}
