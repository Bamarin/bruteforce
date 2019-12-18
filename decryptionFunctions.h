#ifndef _FAKE_DECRYPTION_FUNCTION_H_
#define _FAKE_DECRYPTION_FUNCTION_H_

#include <string>
#include <vector>
#include "stdint.h"

/*
* This function is used to derive a key from the password 
* ( you should ignore that this is just a fake key derivation function )
* The derived key can later be used to decrypt encrypted data
* Input: password
* Output: key
*/
void deriveKeyFromPassword(const std::string& password, std::vector<uint8_t>& key);


#endif /** !_FAKE_DECRYPTION_FUNCTION_H_*/
