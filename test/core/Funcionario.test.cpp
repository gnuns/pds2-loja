#include "doctest.h"
#include <stdio.h>
#include string
#include "../../src/user/Manager.hpp"

using namespace std;
using namespace user;

TEST_CASE("Teste criar Manager") {

  Person* userTest;
  
  string name = "samuel";
  string username = "samuelbraga";
  string password = "123";

  userTest = new Manager(name, username, password);
  CHECK(userTest->getName() == "samuel");
  CHECK(userTest->getUsername() == "samuelbraga");
  CHECK(userTest->getPassword() == "123");
}