#include "AVM.hpp"
#include "Exception.hpp"

static inline void
readStdin(void) {
	std::cout << "read stdin" << std::endl;	
}

static inline void
readFile(char *f) {
	AVM *avm = new AVM();
	std::string	filename(f);
	std::ifstream myfile;
	std::string	line;

	myfile.open(filename);
	while (getline(myfile, line))
		avm->lineAnalysis(line);
	myfile.close();
	delete avm;
}

int
main(int ac, char **av) {
	if (ac > 2) {
		std::cout << "usage: ./avm (optional file)." << std::endl;
		return (0);
	}
	try {
    	if (ac == 2)
    	    readFile(av[1]);
    	if (ac == 1)
    	    readStdin();
	} catch (SyntaxError &e) {
			std::cout << e.what() << std::endl;
	}
	catch (ElementNbError &e) {
			std::cout << e.what() << std::endl;
	}
	return (0);
}