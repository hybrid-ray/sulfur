#ifndef PRINTS_HPP
#define PRINTS_HPP

#include <iostream>
#include <string>

#define CONSOLE_BLACK "\x1B[30m"
#define CONSOLE_RED "\x1B[31m"
#define CONSOLE_GREEN "\x1B[32m"
#define CONSOLE_YELLOW "\x1B[33m"
#define CONSOLE_BLUE "\x1B[34m"
#define CONSOLE_MAGENTA "\x1B[35m"
#define CONSOLE_CYAN "\x1B[36m"
#define CONSOLE_WHITE "\x1B[37m"
#define CONSOLE_BRIGHT_BLACK "\x1B[90m"
#define CONSOLE_BRIGHT_RED "\x1B[91m"
#define CONSOLE_BRIGHT_GREEN "\x1B[92m"
#define CONSOLE_BRIGHT_YELLOW "\x1B[93m"
#define CONSOLE_BRIGHT_BLUE "\x1B[94m"
#define CONSOLE_BRIGHT_MAGENTA "\x1B[95m"
#define CONSOLE_BRIGHT_CYAN "\x1B[96m"
#define CONSOLE_BRIGHT_WHITE "\x1B[97m"
#define CONSOLE_RESET "\x1B[0m"

// just to keep printing in same style over whole project
inline void printInfo(std::string s) {
	std::cout << CONSOLE_BRIGHT_CYAN "[INFO]: " CONSOLE_RESET << s << std::endl;
}
inline void printWarning(std::string s) {
	std::cout << CONSOLE_BRIGHT_YELLOW "[WARNING]: " CONSOLE_RESET << s << std::endl;
}
inline void printError(std::string s) {
	std::cout << CONSOLE_BRIGHT_RED "[ERROR]: " CONSOLE_RESET << s << std::endl;
}
inline void printFatalError(std::string s) {
	std::cout << CONSOLE_RED "[FATAL_ERROR]: " CONSOLE_RESET << s << std::endl;
}

#endif