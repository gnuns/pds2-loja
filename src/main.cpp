#include <iostream>
#include <string>

#include "core/Session.hpp"
#include "user/Person.hpp"

using namespace std;
using namespace core;
using namespace user;

void startLogin(Session* session) {
  string username, password;
  Person* expectedUser;

  cout << "Digite o nome de usuário:" << endl;
  cin >> username;

  expectedUser = session->getTeam()->getPersonByUsername(username);

  if (expectedUser == nullptr) {
    cout << "Usuário inexistente!";
    return;
  }

  cout << "Digite a senha de " << expectedUser->getName() << endl;
  cin >> password;

  if (!expectedUser->checkPassword(password)) {
    cout << "Senha incorreta!" << endl;
    return;
  }

  session->setCurrentUser(expectedUser);
  cout << "Olá, " << session->getCurrentUser()->getName() << endl;
}

int main() {
  Session *session = new Session;
  startLogin(session);

	return 0;
}
