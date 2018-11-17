#include "DataFile.hpp"

core::DataFile::DataFile (string filePath) : _filePath(filePath) {
  load();
}

void core::DataFile::load () {
  string line, key, value;
  string delimiter = "=";
  auto delimiterPosition = string::npos;
  ifstream myfile(_filePath);

  if (!myfile.is_open()) return;

  while (getline(myfile, line)) {
    delimiterPosition = line.find(delimiter);
    if (delimiterPosition == string::npos) {
      _parameters[line] = "";
      continue;
    }

    key = line.substr(0, delimiterPosition);
    value = line.substr(delimiterPosition + 1, line.length());

    _parameters[key] = value;
  }
}

string core::DataFile::getParam (string key) {
  auto it = _parameters.find(key);

  if (it != _parameters.end()) {
    return _parameters[key];
  }

  return "";
}

map<string, string> core::DataFile::getParametersMap () {
  return _parameters;
}
