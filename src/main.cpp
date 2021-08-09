#include <iostream>
#include <string>
#include "cfgs.hpp"

void printhelp() {
	static const char *helpstr = "Help for Sulfur compiler\n"
		"Usage: sulfur [(flag|file)...]\n"
		"actions:\n"
		"\thelp (h, -h, -?, --help) - shows this\n"
		"\tversion (ver, v, -v, --version) - shows compiler version\n"
		"flags:\n"
		"\t-o <file> - sets output file\n"
		"\t\n"
		"\t\n";
	std::cout << helpstr << std::endl;
}

void printver() {
	std::cout << "v" << SULFUR_VERSION_MAJOR << "." << SULFUR_VERSION_MINOR <<
		SULFUR_VERSION_APPEND << std::endl;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		printhelp();
		return 0;
	}
	// wrap arg into c++ string for more readable comparing
	std::string a1(argv[1]);
	if (a1 == "help" || a1 == "h" || a1 == "-h" || a1 == "-?" || a1 == "--help") {
		printhelp();
		return 0;
	}
	if (a1 == "version" || a1 == "ver" || a1 == "v" || a1 == "-v" || a1 == "--version") {
		printver();
		return 0;
	}
	return 0;
}
