#include <iostream>
#include <string>
#include "../libraries/SearchIndex.h"

using namespace std;

#include "user/Session.hpp"
#include "inventory/Product.hpp"

using namespace std;
using user::Session;
using inventory::Product;

int menu(){
    int x;
    cout << "Gerenciamento de Loja!" << endl;
    cout << "1- Cadastro de Produtos" << endl;
    cout << "0- Sair" << endl;
    cout << "Digite sua opção: "; 
    cin >> x;
    return x;
}

void startLogin(Session** userSession) {
  *userSession = new Session("Testando", "");
}

int main() {
  Session *userSession = nullptr;
  startLogin(&userSession);
  cout << userSession->_username;
  
  int option = menu();
  while (option != 0){
    switch(option){
      
      case 1:
          int index;
          string name;
          string description;
          double price;
          index = getIndex();
          cout << "Digite o nome do Produto: ";
          cin >> name;
          cout << "Digite a descricao do Produto: ";
          cin >> description;
          cout << "Digite o preco do Produto: ";
          cin >> price;
          Product *newProduct = new Product (index, name, description, price);
          newProduct->save();
          cout << "Salvo!" << endl;
      break;
      //default:
        //  cout << "Opcao Invalida tente novamente!";
    }
    option = menu();
  }
	return 0;
}
