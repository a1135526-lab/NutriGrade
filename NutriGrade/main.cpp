#include<iostream>
#include<iomanip>
#include<string>
#include"food.h"
#include"baverage.h"
#include"juice.h"
#include"meal.h"
#include"dessert.h"

using namespace std;

//Baverage("name",
//			calories,
//			protein,
//			fat,
//			saturated fat,
//			trans fat,
//			carbonhydrate,
//			sugar,
//			sodium,
//			calcium,
//			potassium,
//			content,
//			fruit percentage,
//			pulp)  per 100ml

void demo() {
	Food* foodPtr = nullptr;
	try
	{
		Baverage wheatGoodSmelledMilktea("麥香奶茶", 39.4, 0.3, 0.2, 0.2, 0, 9.1, 8.7, 17, 0, 0, false);
		wheatGoodSmelledMilktea.print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Baverage marklessMilk("雜牌牛奶", 66.2, 3.2, 4.0, 2.6, 0, 4.8, 4.6, 40, 100, 0, false);
		marklessMilk.print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Baverage milk("味全牛奶", 65, 3.0, 3.7, 2.4, 0, 5.0, 5.0, 45, 100, 0, false);
		milk.print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Baverage bomi("波蜜果菜汁", 37, 0, 0, 0, 0, 9.3, 8.3, 25, 0, 0, false);
		foodPtr = &bomi;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Baverage eletricWater("電解水", 13, 0.2, 0, 0, 0, 15, 2, 86, 0, 63, false);
		foodPtr = &eletricWater;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Baverage water("鹼性離子水", 1, 0, 0, 0, 0, 0, 0, 0.2, 0, 0, false);
		foodPtr = &water;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Juice bomijuice("葡萄綜合果汁", 56, 0, 0, 0, 0, 14, 13.2, 10, 0, 0, false, 100, false);
		foodPtr = &bomijuice;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Meal bandong("超商雞胸肉餐盒", 136, 9.4, 2.7, 0.6, 0, 18.5, 0.5, 206, 0, 0, 0);
		foodPtr = &bandong;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Meal Curry("Curry", 154, 4.6, 4.8, 2.7, 0, 23.2, 0.7, 223, 0, 0, 0);
		foodPtr = &Curry;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Dessert cake("無花果蛋糕", 407.2, 4.3, 21.4, 11, 0, 50, 21.2, 36, 0, 0, false, false);
		foodPtr = &cake;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
	try
	{
		Dessert eggPineapple("達克瓦茲-鹹蛋黃土鳳梨", -384.2, 7.6, 23.4, 10.8, 0, 37.9, 31, 126, 0, 0, false, false);
		foodPtr = &eggPineapple;
		foodPtr->print();
	}
	catch (const exception& e)
	{
		cerr << "[ERROR] " << e.what() << "\n\n";
	}
}

int main() {
	cout << fixed << setprecision(2);
	
	// 顯示範例
	cout << "是否顯示範例? (Y/n)";
	string usrInput;
	cin >> usrInput;
	if (usrInput.compare("Y") == 0) demo();

	cout << "end\n";
}