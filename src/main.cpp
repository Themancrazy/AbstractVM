#include "AVM.hpp"

static inline void
readStdin(void) {
	std::cout << "read stdin" << std::endl;	
}

static inline void
readFile(char *f) {
	std::string	filename(f);
	std::ifstream myfile;

	myfile.open(filename);
	myfile.close();
	std::cout << "filename: " << filename << std::endl;
}

int
main(int ac, char **av) {
	if (ac > 2) {
		std::cout << "usage: ./avm (optional file)." << std::endl;
		return (0);
	}
    if (ac == 2)
        readFile(av[1]);
    if (ac == 1)
        readStdin();
	return (0);
}