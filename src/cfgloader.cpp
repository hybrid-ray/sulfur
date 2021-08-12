#include "cfgloader.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

std::map<std::string, std::string> cfg;
bool loadcfg() {
	cfg.clear();
	std::ifstream f("./sulfur.cfg");
	if (f.fail()) {
		return true;
	}
	std::string ln;
	while (std::getline(f, ln)) {
		auto i = ln.find('=');
		if (i != ln.npos)
			cfg.insert(std::make_pair(ln.substr(0, i), ln.substr(i + 1)));
	}
	return false;
}
bool gencfg() {
	return true;
}
