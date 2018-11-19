#include <iostream>
#include <string>

#include "main.hpp"


#include "user/Person.hpp"

using namespace std;
using namespace user;

int main() {
  Session *session = new Session;
  startLogin(session);

  while(session->getCurrentUser() != nullptr) {
    awaitCommand(session);
  }

	return 0;
}

void createNewUser(Session* session){
  string name, username, password;
  int option;
  bool isManager;
  
  cout << "Digite o nome do funcionario\n";
  cin >> name;
  cout << "Digite o username do funcionario\n";
  cin >> username;
  cout << "Digite o password do funcionario\n";
  cin >> password;
  cout << "1- Funcionario\n";
  cout << "2- Gerente\n";
  cout << "Opcao: ";
  cin >> option;
  if (option == 1){
    isManager = false;
  }else{
    isManager = true;
  }
  session->getTeam()->addPerson(name, username, password, isManager);
}

void awaitCommand (Session* session) {
  int command;
  
  if (session->getCurrentUser()->isManager()) {
    printManagerCommands();
  } else {
    printEmployeeCommands();
  }

  cin >> command;

  processCommand(command, session);
}

void printEmployeeCommands () {
  cout << "\nOpções:" << endl;
  cout << "\t[1] Ver estoque\n";
  cout << "\t[2] Nova venda\n";
  cout << "\t[0] Sair\n";
}

void printManagerCommands () {
  cout << "\nOpções:" << endl;
  cout << "\t[1] Ver estoque\n";
  cout << "\t[2] Nova venda\n";
  cout << "\t[3] Novo Funcionario\n";
  cout << "\t[0] Sair\n";
}

void processCommand (int command, Session* session) {
  bool isManager = session->getCurrentUser()->isManager();

  switch (command) {
    case 1:
      session->getStock()->listProducts();
      break;
    case 3:
      if (isManager){

      }
    case 0:
      session->logout();
      break;
    default:
      cout << "Comando inválido!\n";
      break;
  }

}


void startLogin (Session* session) {
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
