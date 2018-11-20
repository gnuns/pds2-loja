#include "Session.hpp"

core::Session::Session() {
  _currentUser = nullptr;
  _stock = new Stock;
  _team = new Team;
}

Person* core::Session::getCurrentUser() {
  return _currentUser;
}

void core::Session::setCurrentUser (Person* currentUser) {
  _currentUser = currentUser;
}

Team* core::Session::getTeam() {
  return _team;
}

Stock* core::Session::getStock() {
  return _stock;
}
void core::Session::logout() {
  _currentUser = nullptr;
}
