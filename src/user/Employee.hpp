#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.hpp"

using namespace std;

namespace user {

	class Employee : public Person {
	private:

	public:
		Employee(string name, string namespace, string password);

		//void sell(int "produto")
	};
}

#endif