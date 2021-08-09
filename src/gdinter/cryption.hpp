#include <algorithm>

constexpr unsigned char xorkey = 0x0B;

namespace gdinter {
	// decrypts gd data in-place
	inline void decrypt(unsigned char *ldata, size_t len) {
		// xor
		for (size_t i = 0; i < len; i++) {
			ldata[i] ^= xorkey;
		}
		;//TODO:
	}
}