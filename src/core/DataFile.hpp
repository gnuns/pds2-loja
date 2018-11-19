#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

namespace core {
	/**
	 * Classe para manipulação dos arquivos de dados.
	 * 
	 * Nesta classe é feito o *parsing* dos arquivos "*.data" e "*.idx.data"
	 * que armazenam os dados dos funcionários, das vendas e dos produtos.
	 *
	 */
	class DataFile {
	private:
		const string delimiter = "=";
		string _filePath;
		map<string, string> _parameters;
		void load();
	public:
	    /**
        * Construtor que define o caminho do arquivo a ser manipulado.
        * 
        * @param filePath caminho para o arquivo a ser lido ou escrito
        * @param loadData caso seja `true`, o conteúdo atual do arquivo será
		* 				  processado e carregado no map `_parameters`
        */
		DataFile(string filePath, bool loadData = true);
		/**
        * Retorna o valor de um parâmetro.
        * 
        * @param key chave do parâmetro
		* @return valor do parâmetro ou uma string vazia caso o parâmetro
		*		  não esteja definido
        */
		string getParam(string key);
		/**
		* Retorna o map com os parâmetros carregados.
		* @return map com os parâmetros já carregados
        */
		map<string, string> getParametersMap();
		/**
        * Adiciona um novo parâmetro.
        */
		void setParam(string key, string value = "");
		/**
        * Sobrescreve o arquivo com o conteúdo carregado na memória.
        */
		void save();
	};
}

#endif
