#ifndef MAINHEADER_HPP
# define MAINHEADER_HPP

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <stack>
#include <map>

#ifndef EXCEPTION_HPP
# include "Exception.hpp"
#endif

#ifndef IOPERAND_HPP
# include "IOperand.hpp"
#endif

#ifndef AVM_HPP
# include "AVM.hpp"
#endif

void					cmd_push(IOperand * value);
void					cmd_pop(IOperand *);
void					cmd_dump(IOperand *);
void					cmd_assert(IOperand *value);
void					cmd_add(IOperand *);
void					cmd_sub(IOperand *);
void					cmd_mul(IOperand *);
void					cmd_div(IOperand *);
void					cmd_mod(IOperand *);
void					cmd_print(IOperand *);
void					cmd_exit(IOperand *);

static std::map<std::string, void (*)(IOperand*)> dispatchTable  = {
	{"push", &cmd_push},
	{"pop", &cmd_pop},
	{"dump", &cmd_dump},
	{"assert", &cmd_assert},
	{"add", &cmd_add},
	{"sub", &cmd_sub},
	{"mul", &cmd_mul},
	{"div", &cmd_div},
	{"mod", &cmd_mod},
	{"print", &cmd_print},
	{"exit", &cmd_exit}
};

#endif