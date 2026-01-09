#include<iostream>
#include"juice.h"

using namespace std;

Juice::Juice(string name, double cal, double pro, double fat, double sat, double trans, double carbon, double sug, double na, double ca, double ka, bool content,double percent,bool pulp)
	:Baverage(name,cal,pro,fat,sat,trans,carbon,sug,na,ca,ka,content)
{
	setFruitPercent(percent);
	setPulp(pulp);
}

void Juice::setFruitPercent(double percent) {
	if (percent >= 0)
	{
		fruitPercent = percent;
	}
	else
	{
		throw invalid_argument("Fruit percentage must >= 0");
	}
}

double Juice::getFruitPercent()const {
	return fruitPercent;
}

void Juice::setPulp(bool pulp) {
	pulps = pulp;
}

bool Juice::getPulp()const {
	return pulps;
}

double Juice::calculateScore()const {
	double score = 80;//起始分數
	double negPoint = 0, posPoint = 0;

	negPoint += (getCalories() / 100) * 4;//100kcal -4
	negPoint += getSugar() * 1.5;//1g -1.5
	negPoint += getSatfat() * 2;//1g -2
	negPoint += getSodium() / 100;//100mg -1
	posPoint += getProtein() * 4.5;//1g +4.5
	posPoint += (getCalcium() / 100) * 2.5;//100mg +2.5
	posPoint += (getPotassium() / 100) * 1.5;//100g +1.5
	posPoint += (getContent() == true) ? -5 : 0;

	if (getFruitPercent() >= 100) posPoint += 20;
	else if (getFruitPercent() >= 40) posPoint += getFruitPercent() * 0.15;//1% +0.15
	else if (getFruitPercent() < 10) negPoint += 5;

	if (getPulp()) posPoint += 5;

	score += posPoint - negPoint;

	if (getCalories() < 5 && getSugar() < 0.5)//純水無糖茶給高分
	{
		score += (100 - score) * 0.9;
	}
	if (score > 100) score = 100;
	else if (score < 0)score = 0;

	return score;
}

string Juice::getGrade(double score)const {
	if (score >= 90) return "S (極佳)";
	else if (score >= 78 && score < 90) return "A (健康)";
	else if (score >= 66 && score < 78) return "B (尚可)";
	else if (score >= 54 && score < 66) return "C (需注意)";
	else if (score >= 42 && score < 54) return "D (幾乎不健康)";
	else return "F (不健康)";
}

void Juice::print()const {
	Food::print();
	cout << "Sugar : " << getSugar()
		<< " g\nContent : " << getContent()
		<<"\nFruit Percentage : "<<getFruitPercent()
		<<" %\nPupls : "<<getPulp()
		<< "\nScore : " << calculateScore()
		<< "\nGrade : " << getGrade(calculateScore())
		<< "\n\n";
}