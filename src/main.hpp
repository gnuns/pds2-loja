#include <string>
#include "core/Session.hpp"

/**
 * @namespace core
 * contém classes de uso central no sistema.
 * São classes não relacionadas ao propósito principal da aplicação
 * (venda de produtos e controle de estoque), mas necessárias para
 * a implementação das funcionalidades.
 */
using namespace core;

/**
 * @namespace inventory
 * contém classes relacionadas aos produtos da loja.
 * São classes voltadas para controle de estoque, armazenamento de histórico
 * de vendas e produtos.
 */
using namespace inventory;

/**
 * @namespace user
 * contém classes relacionadas aos usuários do sistema.
 * São classes voltadas para gerenciamento da equipe e de login.
 */
using namespace user;

void startLogin(Session* session);
void awaitCommand(Session* session);
void processCommand(int command, Session* session);
void printEmployeeCommands();
void printManagerCommands();
void createNewUser();
void listUsers();
void deleteUser();
void editUser();