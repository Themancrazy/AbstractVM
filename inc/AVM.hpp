#include "IOperand.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <stack> 

class AVM : public IOperand {
    public:
        AVM(void);
        ~AVM(void);

        AVM         &operator=(const AVM &r);
    private:
        std::stack<eOperandType> AvmStack;
};