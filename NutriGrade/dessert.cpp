#include<iostream>
#include"dessert.h"

using namespace std;

Dessert::Dessert(string name, double cal, double pro, double fat, double sat, double trans, double carbon, double sug, double na, double ca, double ka, bool fru, bool refined)
	:Food(name, cal, pro, fat, sat, trans, carbon, na, ca, ka)
{
	setSugar(sug);
	setFruit(fru);
	setRefinedsugar(refined);
}

void Dessert::setSugar(double sug) {
	if (sug >= 0)
	{
		sugar = sug;
	}
	else
	{
		throw invalid_argument("Sugar must >= 0");
	}
}

double Dessert::getSugar()const {
	return sugar;
}

void Dessert::setFruit(bool fru) {
	fruit = fru;
}

bool Dessert::getFruit() const {
	return fruit;
}

void Dessert::setRefinedsugar(bool refined) {
	refinedsugar = refined;
}

bool Dessert::getRefinedsugar() const {
	return refinedsugar;
}


double Dessert::calculateScore()const {//參考 WHO 的「巨量營養素建議分配範圍 (AMDR)」採PFC平衡指數演算 演算法核心：Modified HSR (Health Star Rating) for Beverages
	double d_cal = getCalories();
	double d_sat = getSatfat();
	double d_trans = getTransfat();
	double d_sugar = getSugar();
	double d_pro = getProtein();

	double score = 100;//從一百開始扣

	double sugar_penalty = d_sugar * 1.5;
	if (getRefinedsugar() == true) {//精製糖，扣分
		sugar_penalty *= 1.2;
	}
	score -= sugar_penalty;

	score -= (d_sat * 2.0);//1g-2
	score -= (d_trans * 20.0);//反式脂肪，扣大分
	if (d_cal > 300) {
		score -= (d_cal - 300) / 10.0;//超過300大卡，每10大卡扣分
	}

	double pro_bonus = min(15.0, d_pro * 2.0);//1g+2
	score += pro_bonus;

	if (getFruit() == true) {
		score += 15.0;//fruit is good
	}

	if (score > 100) return 100.0;
	if (score < 0) return 0.0;

	return score;

}

string Dessert::getGrade(double score)const {
	if (score >= 90) return "S (極佳)";
	else if (score >= 78 && score < 90) return "A (健康)";
	else if (score >= 66 && score < 78) return "B (尚可)";
	else if (score >= 54 && score < 66) return "C (需注意)";
	else if (score >= 42 && score < 54) return "D (幾乎不健康)";
	else return "F (不健康)";
}

void Dessert::print()const {
	Food::print();
	cout << "Sugar : " << getSugar()
		<< " g\nfruit: " << getFruit()
		<< " \nrefinedsugar: " << getRefinedsugar()
		<< "\nScore : " << calculateScore()
		<< "\nGrade : " << getGrade(calculateScore())
		<< "\n\n";
}