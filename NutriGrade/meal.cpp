#include<iostream>
#include"meal.h"

using namespace std;

Meal::Meal(string name, double cal, double pro, double fat, double sat, double trans, double carbon, double sugar, double na, double ca, double ka, double friedper)
    :Food(name, cal, pro, fat, sat,trans, carbon, na, ca, ka)
{
    setFriedpercent(friedper);
    setSugar(sugar);
}

void Meal::setFriedpercent(double friedper) {
    if (friedper < 0) fried = 0;
    else if (friedper > 100) fried = 100;
    else fried = friedper;
}

double Meal::getFriedpercent()const {
    return fried;
}

void Meal::setSugar(double sug) {
    if (sug >= 0)
    {
        sugar = sug;
    }
    else
    {
        throw invalid_argument("Sugar must >= 0");
    }
}

double Meal::getSugar()const {
    return sugar;
}

double Meal::calculateScore() const {

    double d_cal = getCalories();      
    double d_sat = getSatfat();         
    double d_trans = getTransfat(); 
    double d_sod = getSodium();
    double d_sugar = getSugar();
    double d_pro = getProtein();        
    double d_pot = getPotassium();      
    double d_calc = getCalcium();        


    int n_cal = (int)(d_cal / 100.0);//100kcal -1

    int n_sat = (int)(d_sat * 2.0);//1g -2

    double n_sugar = (int)(d_sugar / 5.0);//5g -1

    int n_sod = (int)(d_sod / 100.0);//100mg -1

    double total_N = n_cal + n_sat + n_sugar + n_sod;


    double p_pro_score = d_pro * 1.2;//1g +1.2

    double p_micro = (d_pot / 200.0) + (d_calc / 100.0);

    double total_P = p_pro_score + p_micro;

    double clean_bonus = 0;
    if (d_sat < 1.0 && getFriedpercent() < 5.0) {
        clean_bonus = 5.0;
    }
    double raw_score = total_P - total_N + clean_bonus;
    double final_score = 70.0 + (raw_score * 1.7);

    double fried_penalty = (getFriedpercent() / 10.0) * 3.0; // 加重扣分
    double trans_penalty = d_trans * 15.0; // 反式脂肪 "BIG PENALTY"

    final_score = final_score - fried_penalty - trans_penalty;

    if (final_score > 100) return 100.0;
    if (final_score < 0) return 0.0;

    return final_score;
}


string Meal::getGrade(double score)const {
    if (score >= 90) return "S (極佳)";
    else if (score >= 78 && score < 90) return "A (健康)";
    else if (score >= 66 && score < 78) return "B (尚可)";
    else if (score >= 54 && score < 66) return "C (需注意)";
    else if (score >= 42 && score < 54) return "D (幾乎不健康)";
    else return "F (不健康)";
}

void Meal::print()const {
    Food::print();
    cout << "Meal : " << getFriedpercent()
        << " % are fried."
        <<"\nSugar : "<<getSugar()
        << " g\nScore : " << calculateScore()
        << "\nGrade : " << getGrade(calculateScore())
        << "\n\n";
}