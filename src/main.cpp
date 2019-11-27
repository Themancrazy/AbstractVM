#include "MainHeader.hpp"

static inline void
readStdinToFile(void) {
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
		if (ac == 1)
    	    readStdinToFile();
    	if (ac == 2)
    	    readFile(av[1]);
	} catch (std::exception &e) {
			std::cout << "Error: \x1b[91m" << e.what() << "\x1b[0m"<< std::endl;
	}
	return (0);
}