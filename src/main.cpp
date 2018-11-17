#include <iostream>
#include <string>
#include "../libraries/SearchIndex.h"

#include "core/Session.hpp"
#include "user/Person.hpp"

using namespace std;
using namespace core;
using namespace user;

void startLogin(Session* session) {
  string username, password;
  cout << "Digite o nome de usuário:" << endl;
  cin >> username;
  cout << "Digite a senha do usuário " << username << endl;
  cin >> password;
  session->tryToLogin(username, password);

  if (session->getCurrentUser() != nullptr) {
    cout << "Olá, " << session->getCurrentUser()->getName() << endl;
  }
}

int main() {
  Session *session = new Session;
  startLogin(session);

	return 0;
}
