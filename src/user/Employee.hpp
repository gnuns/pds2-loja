#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.hpp"
#include <string>

using namespace std;

namespace user {

	class Employee : public Person {
	private:

	public:
		Employee(string, string, string);
		const bool isManager () override { return false; }
	};
}

#endif
