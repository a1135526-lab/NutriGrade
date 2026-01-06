#pragma once
#include"food.h"
using namespace std;

class Dessert : public Food
{
public:
	Dessert(string, double, double, double, double, double, double, double, double, double, double, bool, bool);
	~Dessert() {};
	void setSugar(double);
	double getSugar()const;
	void setFruit(bool);
	bool getFruit() const;
	void setRefinedsugar(bool);
	bool getRefinedsugar() const;

	virtual double calculateScore()const override;
	virtual string getGrade(double)const override;
	virtual void print()const override;

private:
	double sugar;
	bool fruit;
	bool refinedsugar;
};



