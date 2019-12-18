#pragma once

#include <string>

class Brute
{
	bool init;
	size_t length;
	std::string values;
	std::string lastGuess;
	void increment(std::string& guess, int pos);


public:
	Brute(const size_t length, std::string values);
	Brute(const size_t length, std::string values, std::string init);
	~Brute();
	std::string generatePassword();
};

