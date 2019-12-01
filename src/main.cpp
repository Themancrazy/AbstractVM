#include "MainHeader.hpp"
#include <stdio.h>

static inline void
readFile(const char *f, bool isStdin) {
	AVM *avm = new AVM();
	bool isExit = false;
	std::string	filename(f);
	std::ifstream myfile;
	std::string	line;

	myfile.open(filename);
	while (getline(myfile, line)) {
		try {
			avm->lineAnalysis(line, isStdin, &isExit);
		}
		catch (std::exception &e) {
			std::cout << "\x1b[1mError: \x1b[91m" << e.what() << "\x1b[0m"<< std::endl;
		}
	}
	if (isExit == false)
		throw NoExit();
	myfile.close();
	myfile.open(outputFilename);
	std::cout << "\x1b[1m\x1b[92m";
	std::cout << "##########################################################################################" << std::endl;
	std::cout << "                                        \x1b[36m\x1b[4mOutput:\x1b[0m\x1b[1m\x1b[92m" << std::endl;
	std::cout << "                                                                                          " << std::endl;
	while (getline(myfile, line)) {
		std::cout << "\t\t\t                  \x1b[33m" << line << "\x1b[92m" << std::endl;
	}
	std::cout << "##########################################################################################\x1b[0m" << std::endl;
	if (remove(outputFilename.c_str()) != 0)
		throw "Couldn't delete file";
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
	std::cout << "\x1b[1m      \t>>\t\x1b[33m";
	while (getline(in, line)) {
		std::cout << "\x1b[0m";
		if (line == ";;")
			break ;
		std::cout << "\x1b[1m      \t>>\t\x1b[33m";
		file << line << std::endl;
	}
	std::cout << "\x1b[0m";
	readFile((filename.c_str()), true);
	file.close();
	if (remove(filename.c_str()) != 0)
		throw "Couldn't delete file";
}

void		printHeader(void) {
	std::cout << "\x1b[1m\x1b[94m";
	std::cout << "##########################################################################################" << std::endl;
	std::cout << "#\x1b[36m  █████╗ ██████╗ ███████╗████████╗██████╗  █████╗  ██████╗████████╗██╗   ██╗███╗   ███╗ \x1b[94m#" << std::endl;
	std::cout << "#\x1b[36m ██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██║   ██║████╗ ████║ \x1b[94m#" << std::endl;
	std::cout << "#\x1b[36m ███████║██████╔╝███████╗   ██║   ██████╔╝███████║██║        ██║   ██║   ██║██╔████╔██║ \x1b[94m#" << std::endl;
	std::cout << "#\x1b[36m ██╔══██║██╔══██╗╚════██║   ██║   ██╔══██╗██╔══██║██║        ██║   ╚██╗ ██╔╝██║╚██╔╝██║ \x1b[94m#" << std::endl;
	std::cout << "#\x1b[36m ██║  ██║██████╔╝███████║   ██║   ██║  ██║██║  ██║╚██████╗   ██║    ╚████╔╝ ██║ ╚═╝ ██║ \x1b[94m#" << std::endl;
	std::cout << "#\x1b[36m ╚═╝  ╚═╝╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝     ╚═══╝  ╚═╝     ╚═╝ \x1b[94m#" << std::endl;
	std::cout << "##########################################################################################" << std::endl;
	std::cout << "          #       \x1b[91m\x1b[4mList of available commands:\x1b[0m\x1b[94m\x1b[1m                            #" << std::endl;
	std::cout << "\x1b[1m\x1b[94m";
	std::cout << "          #                                                              #" << std::endl;
	std::cout << "          #       \x1b[92m*    push [Int8,Int16,Int32,Float,Double](VALUE)\x1b[94m       #" << std::endl;
	std::cout << "          #       \x1b[92m*    pop\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    dump\x1b[94m                                              #" << std::endl;
	std::cout << "          #       \x1b[92m*    assert [Int8,Int16,Int32,Float,Double](VALUE)\x1b[94m     #" << std::endl;
	std::cout << "          #       \x1b[92m*    add\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    sub\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    mul\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    div\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    mod\x1b[94m                                               #" << std::endl;
	std::cout << "          #       \x1b[92m*    print\x1b[94m                                             #" << std::endl;
	std::cout << "          #       \x1b[92m*    exit\x1b[94m                                              #" << std::endl;
	std::cout << "          ################################################################" << std::endl;
	std::cout << "\x1b[0m" << std::endl << std::endl;
}

int
main(int ac, char **av) {
	std::ifstream myfile;

	if (ac > 2) {
		std::cout << "usage: ./avm (optional file)." << std::endl;
		return (0);
	}
	try {
		myfile.open(outputFilename, std::ofstream::out | std::ofstream::trunc);
		myfile.close();
		myfile.open(logsFilename, std::ofstream::out | std::ofstream::trunc);
		myfile.close();
		if (ac == 1) {
			printHeader();
    	    readStdin(std::cin);
		}
    	if (ac == 2)
    	    readFile(av[1], false);
	} catch (std::exception &e) {
			std::cout << "\x1b[1mError: \x1b[91m" << e.what() << "\x1b[0m"<< std::endl;
			return (1);
	}
	return (0);
}