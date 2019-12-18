
#include "decryptionFunctions.h"

void deriveKeyFromPassword(const std::string& password, std::vector<uint8_t>& key)
{
	/** This is a fake password based key derivation function, it's really just a crc64 function */

	uint64_t crcLookup[0x100] = {};

	for (size_t i = 0; i <= 0xff; ++i)
	{
		uint64_t crc = i;

		for (size_t j = 0; j < 8; ++j)
		{
			crc = (crc >> 1) ^ (-int64_t(crc & 1) & 0x42F0E1EBA9EA3693);
		}

		crcLookup[i] = crc;
	}

	uint64_t crcKey = 0;

	for (const char c : password)
	{
		crcKey = (crcKey >> 8) ^ crcLookup[(crcKey & 0xff) ^ c];
	}

	key.resize(16); // 128-bit key size
	*reinterpret_cast<uint64_t*>(key.data()) = crcKey;
}
