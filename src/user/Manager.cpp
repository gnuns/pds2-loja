#include "Manager.hpp"
#include "../core/DataFile.hpp"

using namespace core;

user::Manager::Manager(string name, string username, string password) :
Person(name, username, password) { }

void user::Manager::saveManager(){
	DataFile* currentManagerData;
	currentManagerData = new DataFile((string)"./data/team/" + getUsername() + (string)".data", false);
	currentManagerData->setParam("username", getUsername());
	currentManagerData->setParam("name",  getName());
	currentManagerData->setParam("password", getPassword());
	
	currentManagerData->save();
}
