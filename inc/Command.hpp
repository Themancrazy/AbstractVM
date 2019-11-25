#include "IOperand.hpp"

class Command {
    public:
        Command(void);
        Command(const Command &r);
        ~Command(void);

        Command         &operator=(const Command &r);

        void            dispatchCommand(std::vector<std::string> command);
    private:
};