#include "Command.hpp"

/*------------------CONST/DEST & OVERLOAD-----------------------*/

Command::Command() {
    return ;
}
        
Command::Command(const Command &r) {
    *this = r;
}
Command::~Command() {
    return ;
}

Command         &Command::operator=(const Command &r) {
	(void)r;
	return *this;    
}

void            Command::dispatchCommand(std::vector<std::string> command) {
    (void)command;
}