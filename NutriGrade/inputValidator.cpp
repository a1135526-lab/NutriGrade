#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<stdexcept>
#include"inputValidator.h"

using std::string;
using std::cin;
using std::getline;

string InputValidator::input = "";

void InputValidator::trim(string& s) {
	auto start = s.find_first_not_of(" ");
	if (start == string::npos) s = "";
	auto end = s.find_last_not_of(" ");
	s = s.substr(start, end - start + 1);
}

string InputValidator::getName()
{
	getline(cin, InputValidator::input);
	InputValidator::trim(InputValidator::input);
	return InputValidator::input;
}

bool InputValidator::getBool()
{
	getline(cin, InputValidator::input);
	std::istringstream iss(input);
	char in;
	if (iss >> in)
	{
		in = (char)std::tolower(in);
		if (!iss.eof()) throw std::invalid_argument("Invalid input");

		if (in == 'y' || in == '1') return true;
		if (in == 'n' || in == '0') return false;
	}
	throw std::invalid_argument("Invalid input");
}

char InputValidator::getFoodType()
{
	getline(cin, InputValidator::input);
	std::istringstream iss(input);
	char in;
	if (iss >> in)
	{
		in = (char)std::tolower(in);
		if (!iss.eof()) throw std::invalid_argument("Invalid input");

		if (in == 'b') return 'b';
		if (in == 'j') return 'j';
		if (in == 'm') return 'm';
		if (in == 'd') return 'd';
		if (in == 'e') return 'e';
	}
	throw std::invalid_argument("Invalid input");
}

double InputValidator::getNumber()
{
	getline(cin, InputValidator::input);
	std::istringstream iss(input);
	double in;
	if (iss >> in)
	{
		if (!iss.eof()) throw std::invalid_argument("Invalid input");

		return in;
	}
	throw std::invalid_argument("Invalid input");
}