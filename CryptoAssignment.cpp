
#include <fstream>
#include <iostream>
#include "aes.hpp"
#include "decryptionFunctions.h"

constexpr uint8_t iv[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

/*
	Your assignment is to decrypt the data found in the file "encrypted.bin". The data has been
	encrypted with AES-256. We have provided the IV. You only need to figure out the key.
	The password is 14 characters long and consists of some combination of the ascii characters 'm', 's', 'a' and 'b'
	We have provided an AES library and a key derivation function.
	The decrypted message will begin with the string "MSAB".
*/

constexpr size_t filesize = 0x1300;

bool isCorrect(const uint8_t buffer[filesize])
{
	return (buffer[0] == 'M' &&
			buffer[1] == 'S' &&
			buffer[2] == 'A' &&
			buffer[3] == 'B');
}

uint8_t buffer[16] = { 'M', 'S', 'A', 'B', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b' };

void decrypt() {
	// Load file
	//std::ifstream file("encrypted.bin", std::ios::binary);

	//uint8_t buffer[filesize] = {};
	//file.read(reinterpret_cast<char*>(buffer), filesize);

	// Decrypt
	AES_ctx ctx = {};
	const std::string password = "msabmsabmsabms";
	std::vector<uint8_t> key_vec;

	deriveKeyFromPassword(password, key_vec);

	AES_init_ctx_iv(&ctx, key_vec.data(), iv);
	AES_CBC_decrypt_buffer(&ctx, buffer, 16);

	// If the key is correct, buffer will now contain text that starts with "MSAB"
	if (isCorrect(buffer))
		std::cout << "Correct key: " << password << std::endl;
}

void encrypt() {

	

	// encrypt
	AES_ctx ctx = {};
	const std::string password = "msabmsabmsabms";
	std::vector<uint8_t> key_vec;

	deriveKeyFromPassword(password, key_vec);

	AES_init_ctx_iv(&ctx, key_vec.data(), iv);
	AES_CBC_encrypt_buffer(&ctx, buffer, 16);

	// If the key is correct, buffer will now contain text that starts with "MSAB"
	//if (isCorrect(buffer))
	std::cout << "chipertext: " << buffer << std::endl;
}

int main()
{
	encrypt();
	decrypt();
}
