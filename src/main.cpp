#include "MainHeader.hpp"
#include <stdio.h>

static inline void
readFile(const char *f) {
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

static inline void
readStdin(std::istream& in) {
	std::string line;
	std::string filename;
	std::ofstream file;

	filename = "inputFile";
	file.open(filename);
	while (getline(in, line))
		file << line << std::endl;
	readFile((filename.c_str()));
	file.close();
	if (remove(filename.c_str()) != 0)
		throw "Couldn't delete file";
}

int
main(int ac, char **av) {
	if (ac > 2) {
		std::cout << "usage: ./avm (optional file)." << std::endl;
		return (0);
	}
	try {
		if (ac == 1)
    	    readStdin(std::cin);
    	if (ac == 2)
    	    readFile(av[1]);
	} catch (std::exception &e) {
			std::cout << "Error: \x1b[91m" << e.what() << "\x1b[0m"<< std::endl;
	}
	return (0);
}