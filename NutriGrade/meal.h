#pragma once
#include"food.h"
using namespace std;

class Meal : public Food
{
public:
	Meal(string, double, double, double, double, double, double, double, double, double, double, double);
	~Meal() {};
	void setFriedpercent(double);
	double getFriedpercent() const;
	void setSugar(double);
	double getSugar()const;
	virtual double calculateScore()const override;
	virtual string getGrade(double)const override;
	virtual void print()const override;

private:
	double fried;
	double sugar;
};