#include "doctest.h"

#include <iostream>
#include <string>

#include "user/Manager.hpp"
#include "user/Employee.hpp"
#include "user/Team.hpp"

using namespace user;

TEST_CASE("Teste criar Manager") {

  Person* userTest;
  
  std::string name = "manager";
  std::string username = "manager";
  std::string password = "123";

  userTest = new Manager(name, username, password);
  CHECK(userTest->getName() == "manager");
  CHECK(userTest->getUsername() == "manager");
  CHECK(userTest->checkPassword("123") == true);
}

TEST_CASE("Teste criar Employee") {

  Person* userTest;
  
  std::string name = "employee";
  std::string username = "employee";
  std::string password = "123";

  userTest = new Employee(name, username, password);
  CHECK(userTest->getName() == "employee");
  CHECK(userTest->getUsername() == "employee");
  CHECK(userTest->checkPassword("123") == true);
}

TEST_CASE("Teste Listar Funcionarios") {

  Team* team;
  
  team = new Team;

  team->listUsers();
}

TEST_CASE("Adicionar funcionario Funcionarios") {

  string name = "testeAddFunc";
  string username = "teste";
  string password = "123";
  bool isManager = true;

  Team* team;
  team = new Team;
  team->addPerson(name, username, password, isManager);
  team->listUsers();
}

TEST_CASE("Deletetar funcionario Funcionarios") {

  string name = "testeAddFunc";
  string username = "teste";
  string password = "123";
  bool isManager = true;

  Team* team;
  team = new Team;
  team->addPerson(name, username, password, isManager);
  team->listUsers();
  team->deletePerson(username);
  team->listUsers();
}