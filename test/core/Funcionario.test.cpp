#include "doctest.h"

#include <iostream>
#include <string>

#include "user/Manager.hpp"

using namespace user;

TEST_CASE("Teste criar Manager") {

  Person* userTest;
  
  std::string name = "samuel";
  std::string username = "samuelbraga";
  std::string password = "123";

  userTest = new Manager(name, username, password);
  CHECK(userTest->getName() == "samuel");
  CHECK(userTest->getUsername() == "samuelbraga");
  CHECK(userTest->checkPassword("123") == true);
}