#pragma once
#include<iostream>
#include"food.h"

using namespace std;

class Baverage:public Food
{
public:
	Baverage(string, double, double, double, double, double, double, double, double, double, double, bool);
	virtual ~Baverage() {};
	void setSugar(double);
	double getSugar()const;
	void setContent(bool);
	bool getContent()const;

	virtual double calculateScore()const override;
	virtual string getGrade(double)const override;
	virtual void print()const override;
private:
	double sugar;
	bool content;
};
