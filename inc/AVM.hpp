#ifndef AVM_HPP
# define AVM_HPP

#include "MainHeader.hpp"

class AVM {
    public:
        AVM(void);
        AVM(AVM const &r);
        ~AVM(void);

        AVM         &operator=(const AVM &r);
        
        void        lineAnalysis(std::string line);
        std::string trimLine(std::string old_line);
    private:
        std::stack<eOperandType> AvmStack;
};

#endif
// static std::map<std::string, void (*)(IOperand*)> dispatch_table  = {
//     {"push", &func_push},
//     {"pop", &func_pop},
//     {"dump", &func_dump},
//     {"assert", &func_assert},
//     {"add", &func_add},
//     {"sub", &func_sub},
//     {"mul", &func_mul},
//     {"div", &func_div},
//     {"mod", &func_mod},
//     {"print", &func_print},
//     {"exit", &func_exit}
// };

// static std::map<std::string, eOperandType> types = {
//     {"int8", Int8},
//     {"int16", Int16},
//     {"int32", Int32},
//     {"float", Float},
//     {"double", Double}
// };