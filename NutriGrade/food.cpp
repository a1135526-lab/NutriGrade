#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include"food.h"

using namespace std;

Food::Food(string name, double cal, double pro, double fat, double sat, double trans, double carbon, double na, double ca,double ka)
	:name(name)
{
	setCalories(cal);
	setProtein(pro);
	setFat(fat);
	setCarbonhydrate(carbon);
	setSatfat(sat);
	setTransfat(trans);
	setSodium(na);
	setCalcium(ca);
	setPotassium(ka);
}

string Food::getName()const {
	return name;
}

void Food::setCalories(double cal) {
	if (cal>=0)
	{
		calories = cal;
	}
	else
	{
		throw invalid_argument("Calories must >= 0");
	}
}

double Food::getCalories()const {
	return calories;
}

void Food::setProtein(double pro) {
	if (pro>=0)
	{
		protein = pro;
	}
	else
	{
		throw invalid_argument("Protein must >= 0");
	}
}

double Food::getProtein()const {
	return protein;
}

void Food::setFat(double fa) {
	if (fa>=0)
	{
		fat = fa;
	}
	else
	{
		throw invalid_argument("Fat must >= 0");
	}
}

double Food::getFat()const {
	return fat;
}

void Food::setCarbonhydrate(double carbon) {
	if (carbon>=0)
	{
		carbonhydrate = carbon;
	}
	else
	{
		throw invalid_argument("Carbonhydrate must >= 0");
	}
}

double Food::getCarbonhydrate()const {
	return carbonhydrate;
}

void Food::setSatfat(double sat) {
	if (sat >= 0)
	{
		satfat = sat;
	}
	else
	{
		throw invalid_argument("Satfat must >= 0");
	}
}

double Food::getSatfat()const {
	return satfat;
}

void Food::setTransfat(double trans) {
	if (trans >= 0)
	{
		transfat = trans;
	}
	else
	{
		throw invalid_argument("Transfat must >= 0");
	}
}

double Food::getTransfat()const {
	return transfat;
}

void Food::setSodium(double na) {
	if (na >= 0)
	{
		sodium = na;
	}
	else
	{
		throw invalid_argument("Sodium must >= 0");
	}
}

double Food::getSodium()const {
	return sodium;
}

void Food::setCalcium(double ca) {
	if (ca >= 0)
	{
		calcium = ca;
	}
	else
	{
		throw invalid_argument("Calcium must >= 0");
	}
}

double Food::getCalcium()const {
	return calcium;
}

void Food::setPotassium(double ka) {
	if (ka >= 0)
	{
		potassium = ka;
	}
	else
	{
		throw invalid_argument("Potassium must >= 0");
	}
}

double Food::getPotassium()const {
	return potassium;
}

void Food::print()const {
	cout << "Food : " << getName()
		<< "\nCalories : " << getCalories()
		<< " kcals\nProtein : " << getProtein()
		<< " g\nFat : " << getFat()
		<< " g\nCarbonhydrate : " << getCarbonhydrate()
		<< " g\nSaturated Fat : " << getSatfat()
		<< " g\nTrans fat : " << getTransfat()
		<< " g\nSodium : " << getSodium()
		<< " mg\nCalcium : " << getCalcium()
		<< " mg\nPotassium : " << getPotassium()
		<< " mg\n";
}

