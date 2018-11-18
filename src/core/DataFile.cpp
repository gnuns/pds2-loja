#include "DataFile.hpp"

core::DataFile::DataFile (string filePath, bool loadData) : _filePath(filePath) {
  if (!loadData) return;
  load();
}

void core::DataFile::load () {
  string line, key, value;
  auto delimiterPosition = string::npos;
  ifstream inputFile(_filePath);

  if (!inputFile.is_open()) return;

  while (getline(inputFile, line)) {
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

void core::DataFile::save () {
  ofstream outputFile(_filePath);

  if (!outputFile.is_open()) return;

  for (auto it = _parameters.begin(); it != _parameters.end(); it++) {
    if (it->second.empty()) {
      outputFile << it->first << '\n';
      continue;
    }
    outputFile << it->first << delimiter << it->second << '\n';
	}
}

string core::DataFile::getParam (string key) {
  auto it = _parameters.find(key);

  if (it != _parameters.end()) {
    return _parameters[key];
  }

  return "";
}

void core::DataFile::setParam (string key, string value) {
  _parameters[key] = value;
}

map<string, string> core::DataFile::getParametersMap () {
  return _parameters;
}
