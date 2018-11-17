#include <iostream>
#include <string>

#include "user/Session.hpp"

using namespace std;
using namespace user;

void startLogin(Session** userSession) {
  *userSession = new Session("Testando", "");
}

int main() {
  Session *userSession = nullptr;
  startLogin(&userSession);
  cout << userSession->_username << "nome" << endl;

  // while (userSession != nullptr) {
  //
  //   cout << "nome" << endl;
  // }

	return 0;
}
