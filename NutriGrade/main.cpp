#include<iostream>
#include<iomanip>
#include"food.h"
#include"baverage.h"
#include"juice.h"
#include"meal.h"
#include"dessert.h"

using namespace std;

//Baverage("name",calories,protein,fat,saturated fat,trans fat,carbonhydrate,sugar,sodium,calcium,potassium,content,fruit percentage,pulp)  per 100ml

int main() {
	cout << fixed << setprecision(2);
	
	Food* foodPtr = nullptr;
	try
	{
		Baverage wheatGoodSmelledMilktea("³Á­»¥¤¯ù", 39.4, 0.3, 0.2, 0.2, 0, 9.1, 8.7, 17, 0, 0, false);
		wheatGoodSmelledMilktea.print();
	}
	catch (const exception&e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Baverage marklessMilk("ÂøµP¤û¥¤", 66.2, 3.2, 4.0, 2.6, 0, 4.8, 4.6, 40, 100, 0, false);
		marklessMilk.print();
	}
	catch (const exception&e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Baverage milk("¨ý¥þ¤û¥¤", 65, 3.0, 3.7, 2.4, 0, 5.0, 5.0, 45, 100, 0, false);
		milk.print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Baverage bomi("ªi»eªGµæ¥Ä", 37, 0, 0, 0, 0, 9.3, 8.3, 25, 0, 0, false);
		foodPtr = &bomi;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Baverage eletricWater("¹q¸Ñ¤ô", 13, 0.2, 0, 0, 0, 15, 2, 86, 0, 63, false);
		foodPtr = &eletricWater;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Baverage water("ÆP©ÊÂ÷¤l¤ô", 1, 0, 0, 0, 0, 0, 0, 0.2, 0, 0, false);
		foodPtr = &water;
		foodPtr->print();
	}
	catch (const exception & e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Juice bomijuice("¸²µåºî¦XªG¥Ä", 56, 0, 0, 0, 0, 14, 13.2, 10, 0, 0, false, 100, false);
		foodPtr = &bomijuice;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Meal bandong("¶W°ÓÂû¯Ý¦×À\²°", 136, 9.4, 2.7, 0.6, 0, 18.5, 0.5, 206, 0, 0, 0);
		foodPtr = &bandong;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Meal Curry("Curry", 154, 4.6, 4.8, 2.7, 0, 23.2, 0.7, 223, 0, 0, 0);
		foodPtr = &Curry;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Dessert cake("µLªáªG³J¿|", 407.2, 4.3, 21.4, 11, 0, 50, 21.2, 36, 0, 0, false, false);
		foodPtr = &cake;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
	try
	{
		Dessert eggPineapple("¹F§J¥Ë¯÷ÄÐ³J¶À¤g»ñ±ù", -384.2, 7.6, 23.4, 10.8, 0, 37.9, 31, 126, 0, 0, false, false);
		foodPtr = &eggPineapple;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << e.what() << "\n\n";
	}
}