#include "Brute.h"
#include <iostream>



void Brute::increment(std::string& guess, int pos)
{
	if (pos < 0) return;
	else {
		if (pos == 9) {
			std::cout << guess << "\n";
		}
		int v = values.find(guess[pos]);
		if (++v >= values.length()) {
			guess[pos] = values[0];
			increment(guess, pos - 1);
		}
		else guess[pos] = values[v];
	}
}

Brute::Brute(const size_t length, std::string values)
{
	init = true;
	this->length = length;
	this->values = values;
	lastGuess = new char[length];
}

Brute::Brute(const size_t length, std::string values, std::string init)
{
	this->init = false;
	this->length = length;
	this->values = values;
	lastGuess = init;
}


Brute::~Brute()
{
}

std::string Brute::generatePassword()
{
	if (init) {
		int i;
		char *pwd = new char[length];
		for (i = 0; i < length; i++) {
			pwd[i] = values[0];
		}
		pwd[i] = '\0';
		init = false;
		return lastGuess=pwd;
	}
	else{
		increment(lastGuess, length-1);
		return lastGuess;
	}
}
