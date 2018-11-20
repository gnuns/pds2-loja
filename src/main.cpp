#include <iostream>
#include <string>

#include "main.hpp"


#include "user/Person.hpp"
#include "inventory/Sale.hpp"
#include "inventory/SalesHistory.hpp"

using namespace std;
using namespace user;
using namespace inventory;
int main() {
  // std::cout << "\x1B[2J\x1B[H";
  
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

  cout << "\nSelecione: ";
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



void startSale(Session* session){

    int productId, quantProduct, lastId, entrada = 1;
      SalesHistory* salesHistory = new SalesHistory(session);
      map<int, Sale*> sales = salesHistory->getSales();
      for (auto it = sales.begin(); it != sales.end(); it++) {
		     lastId = it->first;
	    } 
      lastId ++;
      Sale* sale = new Sale(lastId, session->getCurrentUser(), "20/11/2018");
      map<int, int> items;
      while(entrada == 1) {
        cout << "\nDigite o código do produto ou (0) para outras opções: ";
        cin >> productId;

        if(!session->getStock()->getProductById(productId)){
           cout << "\nCódigo inválido!";
           continue;
        }

        if(productId == 0){
          cout << "\nCancelar (0) | Adicionar item (1) | Registrar venda (2): ";
          cin >> entrada;
    
          if(entrada == 1){
            continue;
          }else{
            break;
          }
        }

        cout << "Digite a quantidade: ";
        cin >> quantProduct;
        sale->addItem(session->getStock()->getProductById(productId), quantProduct);
      }


      items = sale->getItems();
      cout << "\n---------------------------- \n";

      for(auto it = items.begin(); it != items.end(); it++) {
        cout << session->getStock()->getProductById(it->first)->getName() 
        << " x " << it->second << "\n"; 
      }

      cout << "\n";
      cout << "\nValor Total: R$" << sale->getTotalPrice();
      cout << "\nVenda realizada com sucesso!";

      cout << "\n----------------------------";


      if(entrada == 0){
        return;
      }

      salesHistory->addSale(sale);
      // salesHistory;
      //delete sale;
}


void processCommand (int command, Session* session) {
  bool isManager = session->getCurrentUser()->isManager();
  
  switch (command) {
    case 1:
      session->getStock()->listProducts();
      break;

    case 2:
      session->getStock()->listProducts();
      startSale(session);
      break;  
    case 3:
      if (isManager){

      }
      break;
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

  cout << "Digite o nome de usuário: ";
  cin >> username;

  expectedUser = session->getTeam()->getPersonByUsername(username);

  if (expectedUser == nullptr) {
    cout << "Usuário inexistente!";
    return;
  }

  cout << "Digite a senha de " << expectedUser->getName() << " ";
  cin >> password;

  if (!expectedUser->checkPassword(password)) {
    cout << "Senha incorreta!" << endl;
    return;
  }

  session->setCurrentUser(expectedUser);
  cout << "Olá, " << session->getCurrentUser()->getName() << endl;
}
