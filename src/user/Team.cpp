#include "Team.hpp"
#include "../core/DataFile.hpp"
#include <stdexcept>

using namespace core;
using namespace std;

user::Team::Team () {
  int isManager;
  DataFile* peopleList = new DataFile("./data/team.idx.data");
  DataFile* currentPersonData;

  for (auto it : peopleList->getParametersMap()) {
    if (it.first.empty()) continue;
    currentPersonData = new DataFile((string)"./data/team/" + (string)it.first + (string)".data");

    try {
      isManager = stoi(currentPersonData->getParam("isManager"));
    } catch(std::invalid_argument& e) {
      isManager = 0;
    }

    if (isManager) {
      _people[it.first] = new Manager(
        currentPersonData->getParam("name"),
        currentPersonData->getParam("username"),
        currentPersonData->getParam("password")
      );
    } else {
      _people[it.first] = new Employee(
        currentPersonData->getParam("name"),
        currentPersonData->getParam("username"),
        currentPersonData->getParam("password")
      );
    }
  }
}

user::Person* user::Team::getPersonByUsername (string username) {
  auto it = _people.find(username);

  if (it != _people.end()) {
    return _people[username];
  }

  return nullptr;
}

void user::Team::addPerson(string name, string username, string password, bool isManager){
  Person* newPerson;

  if (isManager) {
    newPerson = new Manager(name, username, password);
  } else {
    newPerson = new Employee(name, username, password);
  }

  newPerson->savePerson();

  _people[username] = newPerson;
  savePeople();
}

void user::Team::savePeople() {
  DataFile* teamList = new DataFile("./data/team.idx.data", false);

  for (auto it = _people.begin(); it != _people.end(); it++) {
    teamList->setParam(it->second->getUsername());
    it->second->savePerson();
  }

  teamList->save();
}

void user::Team::deletePerson(string username) {
  DataFile* teamList = new DataFile("./data/team.idx.data", false);
  _people.erase(username);
  savePeople();
  teamList->save();
}

void user::Team::listUsers() {
  for (auto it = _people.begin(); it != _people.end(); it++) {
    printUser(it->second);
  }
}

void user::Team::printUser(Person* person) {
    cout << "#" << person->getUsername() << '\t' << flush;
    cout << person->getName() << '\t' << flush;
}

user::Team::~Team() {
  for (auto it = _people.begin(); it != _people.end(); it++) {
    _people.erase(it);
  }
}
