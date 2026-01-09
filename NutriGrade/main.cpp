#include<iostream>
#include<iomanip>
#include<string>
#include"food.h"
#include"baverage.h"
#include"juice.h"
#include"meal.h"
#include"dessert.h"
#include"inputValidator.h"

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

void foodInfoInput(string& name, double& cal, double& pro, double& fat, double& sat, double& trans, double& carbon, double& sug, double& na, double& ca, double& ka)
{
	cout << "品項名稱: "; 
	name = InputValidator::getName();
	cout << "熱量: ";
	cal = InputValidator::getNumber();
	cout << "蛋白質: ";
	pro = InputValidator::getNumber();
	cout << "脂肪: ";
	fat = InputValidator::getNumber();
	cout << "飽和脂肪: ";
	sat = InputValidator::getNumber();
	cout << "反式脂肪: ";
	trans = InputValidator::getNumber();
	cout << "碳水化合物: ";
	carbon = InputValidator::getNumber();
	cout << "糖: ";
	sug = InputValidator::getNumber();
	cout << "鈉: ";
	na = InputValidator::getNumber();
	cout << "鈣: ";
	ca = InputValidator::getNumber();
	cout << "鉀: ";
	ka = InputValidator::getNumber();
}

int main() {
	cout << fixed << setprecision(2);
	
	// 顯示範例
	cout << "是否顯示範例? (Y/n)";
	if (InputValidator::getBool()) demo();
	while (true)
	{
		cout << "飲料請輸入 b\n果汁請輸入 j\n主餐請輸入 m\n點心請輸入 d\n結束請輸入 e\n";
		cout << "請輸入食物類型 : ";
		string type;
		type = InputValidator::getFoodType();

		// 初始化食物參數與物件指標
		string name;
		double cal, pro, fat, sat, trans, carbon, sug, na, ca, ka, juicePercent, friedPercent;
		bool content, pulp, fruit, refindSugar;
		Food* FoodPtr = nullptr;
		cout << "\n";

		// 針對不同食物類型進行輸入參數與回應
		if (type == "b")
		{
			cout << "您選擇的是飲料類別\n請依序輸入\n";
			foodInfoInput(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka);
			
			cout << "是否有內容物(珍珠,粉角) (Y/n): ";
			content = InputValidator::getBool();

			try
			{
				Baverage beverage(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka, content);
				FoodPtr = &beverage;
				FoodPtr->print();
			}
			catch (const exception& e)
			{
				cerr << "[ERROR] " << e.what() << "\n\n";
			}
		}	
		else if (type == "j")
		{
			cout << "您選擇的是果汁類別\n請依序輸入\n";
			foodInfoInput(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka);

			cout << "是否有內容物(珍珠,粉角) (Y/n): ";
			content = InputValidator::getBool();
			cout << "果汁含量: ";
			juicePercent = InputValidator::getNumber();
			cout << "是否有果肉: ";
			pulp = InputValidator::getBool();

			try
			{
				Juice juice(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka, content, juicePercent, pulp);
				FoodPtr = &juice;
				FoodPtr->print();
			}
			catch (const exception& e)
			{
				cerr << "[ERROR] " << e.what() << "\n\n";
			}
		}
		else if (type == "m")
		{
			cout << "您選擇的是主食類別\n請依序輸入\n";
			foodInfoInput(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka);

			cout << "油炸比例(目視): ";
			friedPercent = InputValidator::getNumber();

			try
			{
				Meal meal(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka, friedPercent);
				FoodPtr = &meal;
				FoodPtr->print();
			}
			catch (const exception& e)
			{
				cerr << "[ERROR] " << e.what() << "\n\n";
			}
		}
		else if (type == "d")
		{
			cout << "您選擇的是點心類別\n請依序輸入\n";
			foodInfoInput(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka);

			cout << "是否有水果 (Y/n): ";
			fruit = InputValidator::getBool();
			cout << "是否為精緻糖 (Y/n): ";
			refindSugar = InputValidator::getBool();

			try
			{
				Dessert dessert(name, cal, pro, fat, sat, trans, carbon, sug, na, ca, ka, fruit, refindSugar);
				FoodPtr = &dessert;
				FoodPtr->print();
			}
			catch (const exception& e)
			{
				cerr << "[ERROR] " << e.what() << "\n\n";
			}
		}
		else if (type == "e") return 0;
	}
}