#include "levels.hpp"

#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include "cryption.hpp"
#include "files.hpp"

namespace gdinter {
	levels::levels() { }
	levels::~levels() { }
	void levels::load() {
		std::string data = gdinter::decryptFile(gdinter::cclocallevels());
		char *d = const_cast<char *>(data.c_str());
		rapidxml::xml_document doc;
		doc.parse<0>(d);
		rapidxml::print(std::cout, doc);
	}
}
