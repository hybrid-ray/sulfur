#ifndef LEVELS_HPP
#define LEVELS_HPP

#include <unordered_map>
#include <string>
//#include "level.hpp"

namespace gdinter {
	class levels {
	public:
		levels();
		~levels();

		void load();
	protected:
		//std::unordered_map<std::string, level> m;
	};
}

#endif
