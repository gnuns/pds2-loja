#include <iostream>
#include <string>

using namespace std;

#include "user/Session.hpp"

using namespace std;
using user::Session;

void startLogin(Session** userSession) {
  *userSession = new Session("Testando", "");
}

int main() {
  Session *userSession = nullptr;
  startLogin(&userSession);
  cout << userSession->_username;

	return 0;
}
