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
	while (true)
	{
		getline(cin, InputValidator::input);
		std::istringstream iss(input);
		char in;
		if (iss >> in)
		{
			in = (char)std::tolower(in);

			if (in == 'y' || in == '1') return true;
			if (in == 'n' || in == '0') return false;
		}
		std::cout << "輸入錯誤，請再輸入一次(Y/n): ";
	}
}

char InputValidator::getFoodType()
{
	while (true) {
		getline(cin, InputValidator::input);
		std::istringstream iss(input);
		char in;
		if (iss >> in)
		{
			in = (char)std::tolower(in);

			if (in == 'b') return 'b';
			if (in == 'j') return 'j';
			if (in == 'm') return 'm';
			if (in == 'd') return 'd';
			if (in == 'e') return 'e';
		}
		std::cout << "輸入錯誤，請再輸入一次(b/j/m/d/e): ";
	}
}

double InputValidator::getNumber()
{
	while (true)
	{
		getline(cin, InputValidator::input);
		std::istringstream iss(input);
		double in;
		if (iss >> in)
		{
			return in;
		}
		std::cout << "輸入錯誤，請再輸入一次(double): ";
	}	
}