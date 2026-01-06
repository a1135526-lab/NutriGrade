#pragma once
#include"baverage.h"
using namespace std;

class Juice:public Baverage
{
public:
	Juice(string, double, double, double, double, double, double, double, double, double, double, bool, double, bool);
	virtual ~Juice() {};

	void setFruitPercent(double);
	double getFruitPercent()const;
	void setPulp(bool);
	bool getPulp()const;

	virtual double calculateScore()const override;
	virtual string getGrade(double)const override;
	virtual void print()const override;
private:
	double fruitPercent;
	bool pulps;
};
