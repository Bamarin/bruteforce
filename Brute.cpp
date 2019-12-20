#include "Brute.h"
#include <iostream>


std::string Brute::initializePassword() {
	int i;
	char *pwd = new char[length];
	for (i = 0; i < length; i++) {
		pwd[i] = values[0];
	}
	pwd[i] = '\0';
	init = false;
	return pwd;
}

void Brute::increment(std::string& guess, int pos)
{
	if (pos < 0) return;
	else {
		if (pos == 6) {
			std::cout << guess << "\n";	//print the tested password every now an then (every 4^7 passwords)
		}
		int v = values.find(guess[pos]);
		if (++v >= values.length()) {	//carry
			guess[pos] = values[0];
			increment(guess, pos - 1);
		}
		else guess[pos] = values[v];
	}
}

std::string Brute::generatePassword()
{
	if (init) {
		return lastGuess = initializePassword();
	}
	else {
		increment(lastGuess, length - 1);
		return lastGuess;
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



