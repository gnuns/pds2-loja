#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <string>

#include "inventory/Stock.hpp"
#include "user/Person.hpp"
#include "user/Team.hpp"

using namespace std;
using namespace inventory;
using namespace user;

namespace core {
	/**
	 * Classe para controle da sessão do usuário.
	 * 
	 * Esta classe controla o *estado* do sistema. Nela ficam armazenados
	 * ponteiros para o usuário logado, para a classe de equipe e para
	 * a classe de estoque.
	 */
	class Session {
	private:
		Person* _currentUser;
		Stock* _stock;
		Team* _team;
	public:
		/**
        * Construtor que define os dados inicias da sessão.
		* Aqui são inicializados os dados de estoque e da equipe
		* a partir dos arquivos `.data`.
		* O `_currentUser` é inicializado com `nullptr`.
        */
		Session();
		/**
        * Retorna o usuário logado.
		* @return o valor do `_currentUser`, que será `nullptr` caso
		* o usuário não esteja logado.
        */
		Person* getCurrentUser();
		Stock* getStock();
		Team* getTeam();
		void setCurrentUser(Person*);
		void logout();
	};
}

#endif
