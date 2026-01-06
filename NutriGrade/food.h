#pragma once
#include<iostream>

using namespace std;

class Food
{
public:
	Food(string, double, double, double, double, double, double, double, double, double);
	virtual ~Food() { };
	string getName()const;
	void setCalories(double);
	double getCalories()const;
	void setProtein(double);
	double getProtein()const;
	void setFat(double);
	double getFat()const;
	void setCarbonhydrate(double);
	double getCarbonhydrate()const;
	void setSatfat(double);
	double getSatfat()const;
	void setTransfat(double);
	double getTransfat()const;
	void setSodium(double);
	double getSodium()const;
	void setCalcium(double);
	double getCalcium()const;
	void setPotassium(double);
	double getPotassium()const;
	
	virtual double calculateScore()const = 0;
	virtual string getGrade(double)const = 0;
	virtual void print()const;
private:
	string name;
	double calories;
	double protein;
	double fat;
	double carbonhydrate;
	double satfat;
	double transfat;
	double sodium;
	double calcium;
	double potassium;
};

