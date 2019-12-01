#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include "MainHeader.hpp"

struct SyntaxError : public std::exception {
            const char*     what() const throw();
};

struct ElementNbError : public std::exception {
            const char*     what() const throw();
};

struct UnknownInstruction : public std::exception {
            const char*     what() const throw();
};

struct OverflowError : public std::exception {
            const char*     what() const throw();
};

struct UnderflowError : public std::exception {
            const char*     what() const throw();
};

struct InvalidPop : public std::exception {
            const char*     what() const throw();
};

struct DivisionByZero : public std::exception {
            const char*     what() const throw();
};

struct NoExit : public std::exception {
            const char*     what() const throw();
};

struct InvalidAssert : public std::exception {
            const char*     what() const throw();
};

struct InvalidPrint : public std::exception {
            const char*     what() const throw();
};

struct InvalidOperationStack : public std::exception {
            const char*     what() const throw();
};

#endif