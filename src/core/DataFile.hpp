#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

namespace core {
	/**
	 *  Classe para manipulação dos arquivos de dados.
	 *	Nesta classe é feito o "parsing" dos arquivos "*.data" e "*.idx.data"
	 *	que armazenam os dados dos funcionários, das vendas e dos produtos.
	 */
	class DataFile {
	private:
		const string delimiter = "=";
		string _filePath;
		map<string, string> _parameters;
		void load();
	public:
		DataFile(string filePath, bool loadData = true);
		string getParam(string);
		map<string, string> getParametersMap();
		void setParam(string key, string value = "");
		void save();
	};
}

#endif
