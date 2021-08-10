#include <string>
#include <b64.hpp>

constexpr unsigned char xorkey = 0x0B;

namespace gdinter {
	// decrypts gd data
	inline std::string decrypt(std::string dat) {
		std::string d(dat);
		// xor
		for (size_t i = 0; i < d.size(); i++) {
			d[i] ^= xorkey;
		}
		// base64
		std::string d2(b64decode(d));
		// gzip
	}
}