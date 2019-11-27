#include "MainHeader.hpp"

/*------------------CONST/DEST & OVERLOAD-----------------------*/

AVM::AVM(void) {
	return ;
}

AVM::AVM(AVM const &r) {
	*this = r;
}

AVM::~AVM(void) {
	return ;
}

AVM         &AVM::operator=(const AVM &r) {
	(void)r;
	return *this;    
}

/*------------------LINE_MANAGEMENT-----------------------*/

std::string AVM::trimLine(std::string old_line) {
	int	j = 0;
	std::string new_line;

	boost::algorithm::trim(old_line);
	std::replace( old_line.begin(), old_line.end(), '\t', ' ');
	new_line = old_line;
	for (int i = -1; i < (int)old_line.length(); ++i) {
		if (old_line[i] == ' ') {
			while (old_line[i] == ' ') {
				++i;
			}
			new_line[j] =  ' ';
			++j;
		}
		new_line[j] = old_line[i];
		++j;
	}
	new_line.erase(j);
	return (new_line);
}

void		AVM::lineAnalysis(std::string line) {
	std::vector<std::string> command;

	line = trimLine(line);
	boost::split(command, line, boost::is_any_of(" "));
	if (command.size() > 2)
		throw ElementNbError();
	if (command.size() != 0)
		dispatchCmd(command);
}

void		AVM::dispatchCmd(std::vector<std::string> cmd) {
	std::cout << "\"" << cmd[0] << "\"" << std::endl;
	dispatchTable.find(cmd[0]);

	// it->second;
	// if (it == dispatchTable.end())
	// 	throw UnknownInstruction();
	// std::cout << "cmd is: " << it->first << std::endl;
	// std::cout << cmd[0] << std::endl;
}