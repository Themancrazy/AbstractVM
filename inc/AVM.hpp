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
        
        void        lineAnalysis(std::string line);
        std::string trimLine(std::string old_line);
        void        dispatchCmd(std::vector<std::string> cmd);
    private:
        std::stack<eOperandType> AvmStack;
};

#endif