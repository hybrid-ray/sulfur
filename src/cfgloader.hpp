#ifndef CFGLOADER_HPP
#define CFGLOADER_HPP

#include <map>
#include <string>

extern std::map<std::string, std::string> cfg;
bool loadcfg();
bool gencfg();

#endif