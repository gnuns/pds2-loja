#include "Employee.hpp"
#include "../core/DataFile.hpp"

using namespace core;

user::Employee::Employee(string name, string username, string password) :
Person(name, username, password) { }

void user::Employee::saveEmployee(){
	DataFile* currentEmployeeData;
	currentEmployeeData = new DataFile((string)"./data/team/" + getUsername() + (string)".data", false);
	currentEmployeeData->setParam("username", getUsername());
	currentEmployeeData->setParam("name",  getName());
	currentEmployeeData->setParam("password", getPassword());
	
	currentEmployeeData->save();
}

