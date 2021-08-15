#include "levels.hpp"

#include <iostream>
#include <rapidxml/rapidxml.hpp>
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
		rapidxml::xml_node<> *plist = doc.first_node();
		rapidxml::xml_node<> *dict = plist->first_node();
		rapidxml::xml_node<> *leveldict = dict->first_node("d");
		rapidxml::xml_node<> *head = leveldict->first_node(); // <k>_isArr</k>
		rapidxml::xml_node<> *lend = leveldict->last_node();
		head->next_sibling(); // <t />
		head->next_sibling(); // <k>k_0</k>
		levelcount = 1;
		for (; head < lend; head->next_sibling(), levelcount++) {
			head->next_sibling(); // level data
			rapidxml::xml_node<> *ldat = head->first_node();
			; // TODO:
		}
	}
}
