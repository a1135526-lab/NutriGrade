#include<iostream>
#include"baverage.h"

using namespace std;

Baverage::Baverage(string name, double cal, double pro, double fat, double sat, double trans, double carbon, double sug, double na, double ca, double ka, bool content)
	:Food(name, cal, pro, fat, sat, trans, carbon, na, ca, ka)
{
	setSugar(sug);
	setContent(content);
}

void Baverage::setSugar(double sug) {
	if (sug>=0)
	{
		sugar = sug;
	}
	else
	{
		throw invalid_argument("Sugar must >= 0");
	}
}

double Baverage::getSugar()const {
	return sugar;
}

void Baverage::setContent(bool cont) {
	content = cont;
}

bool Baverage::getContent()const {
	return content;
}

double Baverage::calculateScore()const {//參考 WHO 的「巨量營養素建議分配範圍 (AMDR)」採PFC平衡指數演算 演算法核心：Modified HSR (Health Star Rating) for Beverages
	double score = 80;//起始分數
	double negPoint = 0, posPoint = 0;
	
	negPoint += (getCalories() / 100) * 4;//100kcal -4
	negPoint += getSugar() * 1.8;//1g -1.8
	negPoint += getSatfat() * 2;//1g -2
	negPoint += getSodium() / 100;//100mg -1
	posPoint += getProtein() * 4.5;//1g +4.5
	posPoint += (getCalcium() / 100) * 2.5;//100mg +2.5
	posPoint += (getPotassium() / 100) * 1.5;//100g +1.5
	posPoint += (getContent() == true) ? -5 : 0;
	score += posPoint - negPoint;

	if (getCalories()<5&&getSugar()<0.5)//純水無糖茶給高分
	{
		score += (100 - score) * 0.9;
	}

	if (score>100) score = 100;
	else if(score<0)score = 0;

	return score;
}

string Baverage::getGrade(double score)const {
	if (score >= 90) return "S (極佳)";
	else if (score >= 78 && score < 90) return "A (健康)";
	else if (score >= 66 && score < 78) return "B (尚可)";
	else if (score >= 54 && score < 66) return "C (需注意)";
	else if (score >= 42 && score < 54) return "D (幾乎不健康)";
	else return "F (不健康)";
}

void Baverage::print()const {
	Food::print();
	cout << "Sugar : " << getSugar()
		<< " g\ncontent : " << getContent()
		<< "\nScore : " << calculateScore()
		<< "\nGrade : " << getGrade(calculateScore())
		<< "\n\n";
}