#include <string>
#include "core/Session.hpp"

/**
 * @namespace core
 * O namespace core contém classes de uso central no sistema.
 * São classes não relacionadas ao propósito principal da aplicação
 * (venda de produtos e controle de estoque), mas necessárias para
 * a implementação das funcionalidades.
 */
using namespace core;

void startLogin(Session* session);
void awaitCommand(Session* session);
void processCommand(int command, Session* session);
void printEmployeeCommands();
void printManagerCommands();
void createNewUser();
void listUsers();
void deleteUser();
void editUser();