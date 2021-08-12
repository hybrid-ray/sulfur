#include <iostream>
#include <string>
#include "gdinter/cryption.hpp"
#include "cfgloader.hpp"
#include "cfgs.hpp"
#include "prints.hpp"

void printhelp() {
	static const char *helpstr = "Help for Sulfur compiler\n"
		"Usage: sulfur [(flag|file)...]\n"
		"actions:\n"
		"\thelp (h, -h, -?, --help) - shows this\n"
		"\tversion (ver, v, -v, --version) - shows compiler version\n"
		"flags:\n"
		"\t--debug-config - prints config\n"
		"\t--debug-decode - prints CCLocalLevels.dat but decrypted\n"
		"\t--open-config <editor> - opens config file using <editor>\n"
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
	std::string a(argv[1]);
	if (a == "help" || a == "h" || a == "-h" || a == "-?" || a == "--help") {
		printhelp();
		return 0;
	}
	if (a == "version" || a == "ver" || a == "v" || a == "-v" || a == "--version") {
		printver();
		return 0;
	}
	if (loadcfg()) {
		printWarning("Failed to open sulfur.cfg file.");
		printInfo("Attempting to generate it.");
		if (gencfg()) {
			printFatalError("Failed generating sulfur.cfg file.");
			return -1;
		} else {
			printInfo("sulfur.cfg file generated. Configurate Sulfur compiler by modifying it.");
			printInfo("You can also use 'sulfur --open-config <editor>' to edit it");
		}
		if (loadcfg()) {
			printFatalError("Failed reading the newly generated sulfur.cfg");
			return -1;
		}
	}
	for (int i = 0; i < argc; ++i) {
		if (!*argv[i])
			continue;
		a = std::string(argv[i]);
		if (a[0] == '-') {
			if (a == "--debug-config") {
				for (auto &p : cfg) {
					std::cout << p.first << ": " << p.second << std::endl;
				}
			} else if (a == "--debug-decode") {
				//gdinter::decrypt(gdinter::cclocallevels());
			} else if (a == "--open-config") {
				if (++i >= argc) {
					printFatalError("--open-config needs editor");
					return -1;
				}
				std::string cmd = std::string(argv[i]) + " ./sulfur.cfg";
				system(cmd.c_str());
			}
		} else { // file to compile
			;
		}
	}
	return 0;
}
