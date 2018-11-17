#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

namespace core {

	class DataFile {
	private:
		string _filePath;
		map<string, string> _parameters;
		void save();
		void load();
	public:
		DataFile(string);
		string getParam(string);
		map<string, string> getParametersMap();
	};
}

#endif
