#include "Employee.hpp"
#include "../core/DataFile.hpp"

using namespace core;

user::Employee::Employee(string name, string username, string password) :
Person(name, username, password) { }
