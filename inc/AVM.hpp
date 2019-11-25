#include "Command.hpp"

class AVM {
    public:
        AVM(void);
        AVM(AVM const &r);
        ~AVM(void);

        AVM         &operator=(const AVM &r);
        
        struct SyntaxError : public std::exception {
            const char*     what() const throw();
        };
        struct ElementNbError : public std::exception {
            const char*     what() const throw();
        };

        void        lineAnalysis(std::string line);
        std::string trimLine(std::string old_line);
    private:
        std::stack<eOperandType> AvmStack;
};
        