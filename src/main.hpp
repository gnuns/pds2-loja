#include <string>
#include "core/Session.hpp"

using namespace core;

void startLogin(Session* session);
void awaitCommand(Session* session);
void processCommand(int command, Session* session);
void printEmployeeCommands();
void printManagerCommands();
