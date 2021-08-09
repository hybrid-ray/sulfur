#include <iostream>
#include <string>
#include "cfgs.hpp"

int main(int argc, char **argv) {
	bool help = argc == 1;
	for (int i = 1; i < argc; i++) {
		std::string arg = std::string(argv[i]);
		if (arg[0] == '-') {
			switch (arg[1]) {
			case 'v':
				std::cout << "Sulfur compiler " << SULFUR_VERSION_MAJOR << "." << SULFUR_VERSION_MINOR << std::endl;
				break;
			case 'h':
			case '?':
				help = true;
				break;
			}
		}
	}
	std::cout << "Hi!" << std::endl;
	return 0;
}
