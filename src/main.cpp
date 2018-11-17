#include <iostream>
#include <string>

using namespace std;

#include "user/Session.hpp"
#include "invetory/Product.hpp"

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
  
  int option = -1;
  while (option != 0){
    option = menu();
    switch(option){
      case 1:
        string name;
        string description;
        cout << "Digite o nome do Produto: ";
        cin >> name;
        cout << "Digite a descricao do Produto";
        cin >> description;
        Product *newProduct = new Product (name, description);
      default:
        cout << "Opcao Invalida tente novamente!";
        break;
    }
  }
	return 0;
}
