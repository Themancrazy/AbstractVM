#ifndef AVM_HPP
# define AVM_HPP

#include "MainHeader.hpp"

// template<typename T>
// class AVMStack {
//     public:

//     private:
//         std::stack<T>      element;
// };

class AVM {
	public:
		AVM(void);
		AVM(AVM const &r);
		~AVM(void);

		AVM         &operator=(const AVM &r);
		
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
		void        			lineAnalysis(std::string line, bool isStdin, bool *isExit);
		std::string 			trimLine(std::string old_line);
		void        			dispatchCmd(std::vector<std::string> cmd);
	private:
		std::deque<IOperand*>	avmStack;
		bool					_isExit;
};

static std::map<std::string, void (AVM::*)(IOperand*)> dispatchTable  = {
		{"push", &AVM::cmd_push},
		{"pop", &AVM::cmd_pop},
		{"dump", &AVM::cmd_dump},
		{"assert", &AVM::cmd_assert},
		{"add", &AVM::cmd_add},
		{"sub", &AVM::cmd_sub},
		{"mul", &AVM::cmd_mul},
		{"div", &AVM::cmd_div},
		{"mod", &AVM::cmd_mod},
		{"print", &AVM::cmd_print},
		{"exit", &AVM::cmd_exit}
};

#endif