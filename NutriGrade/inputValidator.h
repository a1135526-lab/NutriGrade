#pragma once
#include<string>

class InputValidator {
private:
	static std::string input;
	static void trim(std::string&);
	InputValidator() = delete; // 完全靜態類別，禁止建立物件
public:
	static std::string getName();
	static bool getBool();
	static char getFoodType();
	static double getNumber();
};