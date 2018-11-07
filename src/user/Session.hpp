#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>

using namespace std;

namespace user {

	class Session {
	private:
		Person _person;
  public:
    Session(string username, string password);
    
	};
}

#endif
