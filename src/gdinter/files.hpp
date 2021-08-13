#ifndef FILES_HPP
#define FILES_HPP

#include <fstream>
#include <sstream>
#include <string>
#include "../cfgloader.hpp"
#include "../prints.hpp"

namespace gdinter {
	inline std::string cclocallevels() {
		auto it = cfg.find("gddatalocation");
		if (it == cfg.end()) {
			printError("The key \"gddatalocation\" was not found in config file.");
			return "";
		}
		std::string path = it->second + "CCLocalLevels.dat";
		std::ifstream f(path);
		if (f.fail()) {
			printError("unable to find CCLocalLevels.dat file");
			printInfo("searched path: " + path);
			return "";
		}
		std::stringstream ss;
		ss << f.rdbuf();
		f.close();
		return ss.str();
	}
}

#endif
