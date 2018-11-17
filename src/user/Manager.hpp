#ifndef MANAGER_H
#define MANAGER_H

#include "Person.hpp"

using namespace std;

namespace user {

	class Manager : public Person {
	public:
		Manager(string, string, string);
		const bool isManager () override { return true; }

	};
}
#endif
