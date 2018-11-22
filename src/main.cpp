#include <iostream>
#include <string>
#include <cmath>

#include "main.hpp"

#include "user/Person.hpp"
#include "inventory/Sale.hpp"
#include "inventory/SalesHistory.hpp"

using namespace std;
using namespace user;
using namespace inventory;
int main() {
  Session *session = new Session;
  startLogin(session);

  while(session->getCurrentUser() != nullptr) {
    awaitCommand(session);
  }

	return 0;
}

void listUsers(Session* session){
  cout << "\n---------------------------- \n";
  session->getTeam()->listUsers();
  cout << "\n---------------------------- \n";
}

void deleteUser(Session* session){
  string username;
  char test;
  cout << "Digite o username para ser deletado: " << endl;
  cin >> username;
  cout << username << "sera deletado. Proceguir [Y/y]: " << endl;
  cin >> test;
  if (test == 'y' || test == 'Y') {
    session->getTeam()->deletePerson(username);
  }
}

void editUser(Session* session) {
  string name, username, password;
  int option;
  bool isManager;
  
  cout << "Digite o novo nome do funcionario\n";
  cin >> name;
  cout << "Digite o novo username do funcionario\n";
  cin >> username;
  cout << "Digite a nova password do funcionario\n";
  cin >> password;
  cout << "1- Funcionario\n";
  cout << "2- Gerente\n";
  cout << "Opcao: ";
  cin >> option;

  isManager = option == 2;

  session->getTeam()->deletePerson(username);
  session->getTeam()->addPerson(name, username, password, isManager);
}

void createNewUser(Session* session) {
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

  isManager = (option == 2);
  
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
  cout << "\t[3] Novo funcionário\n";
  cout << "\t[4] Listar funcionários\n";
  cout << "\t[5] Deletar funcionário\n";
  cout << "\t[6] Editar usuário\n";
  cout << "\t[7] Histórico de vendas\n";
  cout << "\t[0] Sair\n";
}



void startSale(Session* session) {

    int productId, quantProduct, lastId, entrada = 1;
    SalesHistory* salesHistory = new SalesHistory(session);
    map<int, Sale*> sales = salesHistory->getSales();
    for (auto it = sales.begin(); it != sales.end(); it++) {
        lastId = it->first;
    } 
    lastId ++;
    Sale* sale = new Sale(lastId, session->getCurrentUser(), "20/11/2018");
    map<int, int> items;

    while (entrada == 1) {
      cout << "\nDigite o código do produto ou (0) para outras opções: ";
      cin >> productId;


      if (productId == 0) {
        cout << "\nCancelar (0) | Adicionar item (1) | Registrar venda (2): ";
        cin >> entrada;    

        if (entrada == 1) continue;
        break;
      }
      
      if (!session->getStock()->getProductById(productId)) {
          cout << "Código inválido!\n";
          continue;
      }

      if (session->getStock()->getProductById(productId)->getQuantity() <= 0) {
          cout << "Produto indisponivel...\n";
          continue;
      }

      cout << "Digite a quantidade: ";
      cin >> quantProduct;

      if (quantProduct <= 0) {
          cout << "Quantidade invalida!\n";
          continue;
      }

      if (session->getStock()->getProductById(productId)->getQuantity() < quantProduct) {
          cout << "Quantidade indisponivel. Apenas " << session->getStock()->getProductById(productId)->getQuantity() << " unidades no estoque.\n";
          continue;
      }

      sale->addItem(session->getStock()->getProductById(productId), quantProduct);
    }


    items = sale->getItems();
    cout << "\n---------------------------- \n";

    for(auto it = items.begin(); it != items.end(); it++) {
      cout << session->getStock()->getProductById(it->first)->getName() 
      << " x " << it->second << "\n"; 
    }

    if (entrada == 0) {
      cout << "\n";
      cout << "\nVenda cancelada!";
      cout << "\n----------------------------";
    
      return;
    }

    cout << "\n";
    cout << "\nValor Total: R$" << sale->getTotalPrice();
    cout << "\nVenda realizada com sucesso!";

    cout << "\n----------------------------";

    salesHistory->addSale(sale, session);
    delete salesHistory;
    delete sale;
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
      if (isManager) {
        createNewUser(session);
      } else {
        cout << "Acesso negado!" << endl;
      }
    break;
    case 4:
      if (isManager){
        listUsers(session);
      }else{
        cout << "Acesso negado!" << endl;
      }
    break;
    case 5:
      if (isManager){
        deleteUser(session);
      }else{
        cout << "Acesso negado!" << endl;
      }
    break;
    case 6:
      if (isManager) {
        editUser(session);
      } else {
        cout << "Acesso negado!" << endl;
      }
    break;
    case 7: 
    if (isManager) {
      SalesHistory* salesHistory = new SalesHistory(session);
      cout << "---------- Vendas ----------\n";
      salesHistory->listSales();
      cout << "----------------------------";
      delete salesHistory;
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
