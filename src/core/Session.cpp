#include "Session.hpp"

core::Session::Session() {
  _currentUser = nullptr;
  _stock = new Stock;
  _team = new Team;
}

Person* core::Session::getCurrentUser() {
  return _currentUser;
}

void core::Session::tryToLogin(string username, string password) {
  if (username == "funcionario" && password == "123456") {
    _currentUser = new Employee("Funcionário da Loja", username, password);
  } else if (username == "gerente" && password == "123456") {
    _currentUser = new Manager("Gerente da Loja", username, password);
  }
}
