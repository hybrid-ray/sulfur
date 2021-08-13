#ifndef CRYPTION_HPP
#define CRYPTION_HPP

#include <string>
#include <b64.hpp>
#include <gzip.hpp>

constexpr unsigned char xorkey = 0x0B;

namespace gdinter {
	// decrypts gd data
	inline std::string decryptFile(std::string dat) {
		std::string d(dat);
		for (size_t i = 0; i < d.size(); i++) {
			d[i] ^= xorkey;
		}
		std::string d2(b64decode(d));
		return Gzip::decompress(d2);
	}
	// encrypts gd data
	inline std::string encryptFile(std::string dat) {
		std::string d(Gzip::compress(dat));
		std::string d2(b64encode(d));
		for (size_t i = 0; i < d2.size(); i++) {
			d2[i] ^= xorkey;
		}
		return d2;
	}
	//decrypts gd level
	template<bool isOfficial=false>
	inline std::string decryptLevel(std::string dat) {
		std::string d(dat);
		if constexpr (isOfficial) {
			d = d + "H4sIAAAAAAAAA";
		}
		std::string d2(b64decode(dat));
		return Gzip::decompress(d2);
	}
	//encrypts gd level
	template<bool isOfficial=false>
	inline std::string encryptLevel(std::string dat) {
		std::string d(Gzip::compress(dat));
		d = b64encode(d);
		if constexpr (isOfficial) {
			d = d.substr(13);
		}
		return d;
	}
}

#endif
