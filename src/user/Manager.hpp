#ifndef MANAGER_H
#define MANAGER_H

#include "Person.hpp"

using namespace std;

namespace user {

	class Manager : public Person {
	private:

	public:
		Manager(string name, string namespace, string password);

	};
}

#endif

#endif