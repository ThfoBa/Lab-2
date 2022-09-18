//Разработка программного модуля, описывающего работу питомника для собак (классы C++).
#include <iostream>
#include <stdio.h>
#include<string.h>
#include <cstdlib>
#include<malloc.h>

#define LN 100
#define price_korm 15
#define default_pets_name "no_name"
using namespace std;

class pets;
class pitomnik
{
public:
	pitomnik()
	{
		kolvo = 0;
		pribil = 0;
		rasxodi = 0;
		price_kormlenie = price_korm;
	}
	pitomnik(int kolvo, double pribil, double rasxodi, int price_kormlenie)
	{
		this->kolvo = kolvo;
		this->pribil = pribil;
		this->rasxodi = rasxodi;
		this->price_kormlenie = price_kormlenie;
	}
	int get_kolvo()
	{
		return kolvo;
	}
	void set_kolvo(int kolvo)
	{
		this->kolvo = kolvo;
	}
	double get_pribil()
	{
		return pribil;
	}
	void set_pribil(double pribil)
	{
		this->pribil = pribil;
	}
	double get_rasxodi()
	{
		return rasxodi;
	}
	void set_rasxodi(double rasxodi)
	{
		this->rasxodi = rasxodi;
	}
	int get_price_kormlenie()
	{
		return price_kormlenie;
	}
	void set_price_kormlenie(int price_kormlenie)
	{
		this->price_kormlenie = price_kormlenie;
	}
	void read()
	{
		cout << "Количество животных: " << kolvo << endl;
		cout << "Прибыль питомника: " << pribil << endl;
		cout << "Расходы питомника: " << rasxodi << endl;
		cout << "Цена корма для собак: " << price_kormlenie << endl;
	}
	friend pets;
private:
	int kolvo;
	double pribil;
	double rasxodi;
	int price_kormlenie;
};
