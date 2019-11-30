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
	int	j = -1;
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

	if (isspace(line[0]))
		line = trimLine(line);
	boost::split(command, line, boost::is_any_of(" "));
	if (command[0][0] == ';')
		return ;
	if (command.size() > 2)
		throw ElementNbError();
	if (command.size() != 0)
		dispatchCmd(command);
}

bool 			isNumber(std::string s)
{
	int n = s.size();
	if(n == 0)
		return false;

	int i = 0;
	//Skip leading spaces.
	while(s[i] == ' ')
		++i;
     //Significand
   	if(s[i] == '+' || s[i] == '-')
   		++i;
   	int cnt = 0;
     //Integer part
   	while (isdigit(s[i]))
   	{
		++i;
		++cnt;
   	}
     //Decimal point
   	if (s[i] == '.') 
   		++i;
     //Fractional part
   	while (isdigit(s[i]))
   	{
   	    ++i;
   	    ++cnt;
   	}
    if( cnt == 0)
		return false;  //No number in front or behind '.'
     //Skip following spaces;
    while (s[i] == ' ')
		++i;
    return s[i] == '\0';
}


static IOperand		*parseAndCreateOperand(std::vector<std::string> cmd) {
	size_t		posOpen;
	size_t		posClose;
	std::string value;
	eOperandType type;

	if (cmd.size() != 2)
		throw ElementNbError();
	posOpen = cmd[1].find("(");
	posClose = cmd[1].find(")");
	if (posOpen == std::string::npos || posClose == std::string::npos || posOpen > posClose)
		throw SyntaxError();
	if (types.find(cmd[1].substr(0, posOpen)) == types.end())
		throw UnknownInstruction();
	type = types.find(cmd[1].substr(0, cmd[1].find("(")))->second;
	value = cmd[1].substr(posOpen + 1, posClose - posOpen - 1);
	std::cout << "value: " << value << std::endl;
	return (const_cast<IOperand*>(AOperand::factory.createOperand(type, value)));
	// return (nullptr);
}

void		AVM::dispatchCmd(std::vector<std::string> cmd) {
	IOperand *op = nullptr;

	if (cmd[0] == "push" || cmd[0] == "assert")
		op = parseAndCreateOperand(cmd);
		// op = const_cast<IOperand*>(AOperand::factory.createOperand());
	if (dispatchTable.find(cmd[0]) != dispatchTable.end())
		dispatchTable[cmd[0]](op);
	else
		throw UnknownInstruction();
}