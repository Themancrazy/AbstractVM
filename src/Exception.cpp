#include "Exception.hpp"

const char      *SyntaxError::what() const throw() {
    return "Syntax Error";
}

const char      *ElementNbError::what() const throw() {
    return "Wrong number of elements";
}

const char      *UnknownInstruction::what() const throw() {
    return "Unknown instruction given";
}

const char      *OverflowError::what() const throw() {
    return "Overflow on number given";
}

const char      *UnderflowError::what() const throw() {
    return "Underflow on number given";
}

const char      *InvalidPop::what() const throw() {
    return "Trying to pop on empty stack";
}

const char      *DivisionByZero::what() const throw() {
    return "Division by 0 error";
}

const char      *NoExit::what() const throw() {
    return "Missing exit command";
}

const char      *InvalidAssert::what() const throw() {
    return "Top of stack doesn't correspond to assert command value";
}

const char      *InvalidPrint::what() const throw() {
    return "Type on top of stack isn't a Int8 type";
}

const char      *InvalidOperationStack::what() const throw() {
    return "Operation on stack invalid (add needs 2 element in stack for example)";
}
