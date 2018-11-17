#include "Team.hpp"
#include "../core/DataFile.hpp"

using namespace core;
using namespace std;

user::Team::Team () {
  DataFile* peopleList = new DataFile("./data/team.idx.data");
  DataFile* currentPersonData;

  for (auto it : peopleList->getParametersMap()) {
    if (it.first.empty()) continue;
    currentPersonData = new DataFile((string)"./data/team/" + (string)it.first + (string)".data");

    if (stoi(currentPersonData->getParam("isManager")) == 1) {
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
