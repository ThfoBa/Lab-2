//Разработка программного модуля, описывающего работу питомника для собак (классы C++).
#include <iostream>
#include <stdio.h>
#include<string.h>
#include <cstdlib>
#include<malloc.h>
#include <locale.h>

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
class pets : public pitomnik
{
	public: 
		pets()
		{
			strcpy_s(name, default_pets_name);
			age = 0;
			ves = 0;
			health = 0;
			price = 0;
		}
		pets(int kolvo, double pribil, double rasxodi, int price_kormlenie, char name[LN], int age, int ves, int health, double price) : pitomnik(kolvo, pribil, rasxodi, price_kormlenie)
		{
			strcpy_s(this->name, name);
			this->age = age;
			this->ves = ves;
			this->health = health;
			this->price = price;
		}
		void setname(char name[LN])
		{
			strcpy_s(this->name, name);
		}
		void setage(int age)
		{
			this->age = age;
		}
		void setves(int ves)
		{
			this->ves = ves;
		}
		void sethealth(int health)
		{
			this->health = health;
		}
		void setprice(double price)
		{
			this->price = price;
		}
		string getname()
		{
			cout << "Имя животного: " << name << endl;
			return name;
		}
		int getage()
		{
			cout << "Возраст животного (кол-во полных месяцев): " << age << endl;
			return age;
		}
		int getves()
		{
			cout << "Вес животного (в граммах): " << ves << endl;
			return ves;
		}
		void vvod()
		{
			cout << "Введите имя животного: \n";
			rewind(stdin); gets_s(name, LN);
			cout << "Введите возраст животного (кол-во полных месяцев): \n";
			cin >> age;
			cout << "Введите вес животного (в граммах): \n";
			cin >> ves;
			cout << "Введите состояние здоровья животного (целое число от 1 до 10): \n";
			cin >> health;
			cout << "Введите стоимость животного: \n";
			cin >> price;
			kolvo++;
		}
		void vivod()
		{
			cout << "Количество животных: " << kolvo << endl;
			cout << "Прибыль питомника: " << pribil << endl;
			cout << "Расходы питомника: " << rasxodi << endl;
			cout << "Стоимость корма для собак: " << price_kormlenie << endl;
			cout << "Имя животного: " << name << endl;
			cout << "Возраст животного: " << age << endl;
			cout << "Вес животного: " << ves << endl;
			cout << "Состояние здоровья животного: " << health << endl;
			cout << "Стоимость животного: " << price << endl;
		}
		void kormlenie()
		{
			ves += 1;	
			rasxodi = rasxodi + price_kormlenie;
			cout << "Животное накормлено!\n";
		}
		void prodaja()
		{
			pribil += price;
			kolvo -= 1;
			rasxodi -= price_kormlenie;
			strcpy_s(name, default_pets_name);
			age = 0;
			ves = 0;
			health = 0;
			price = 0;
			cout << "Животное продано!\n";
		}
		double add_price(double sum)
		{
			sum += price;
			cout << "Итоговая стоимость животных: " << sum << endl;
			return sum;
		}
	private:
		char name[LN];
		int age;
		int ves;
		int health;
		double price;
};
int main()
{
	setlocale(LC_ALL, "rus");
	double sum = 0;
	char def[LN] = "no_name";
	pets dogs(0, 0, 0, 15, def, 0, 0, 0, 0);
	cout << "После инициализации:" << endl;
	dogs.vivod();
	dogs.vvod();
	cout << "После ввода:" << endl;
	dogs.vivod();
	cout << "После кормления:" << endl;
	dogs.kormlenie();
	dogs.vivod();
	cout << "После продажи:" << endl;
	dogs.prodaja();
	dogs.vivod();
	sum = dogs.add_price(sum);
	pets* dog1 = new pets(0, 0, 0, 15, def, 0, 0, 0, 0);
	cout << "\n" << "Работа с динамическим массивом объектов класса:" << endl;
	cout << "После инициализации:" << endl;
	dog1->vivod();
	dog1->vvod();
	cout << "После ввода:" << endl;
	dog1->vivod();
	cout << "После кормления:" << endl;
	dog1->kormlenie();
	dog1->vivod();
	cout << "После продажи:" << endl;
	dog1->prodaja();
	dog1->vivod();
	sum = dog1->add_price(sum);
	delete dog1;
	cout << "\n" << "Работа с массивом динамических объектов класса:" << endl;
	pets** dogy = new pets * [LN];
	int kol = 0;
	cout << "Введите кол-во животных: " << endl;
	cin >> kol;
	for (int i = 0; i < kol; i++)
	{
		dogy[i] = new pets(i, 0, 0, 15, def, 0, 0, 0, 0);
		dogy[i]->vvod();
	}
	for (int i = 0; i < kol; i++)
	{
		dogy[i]->set_kolvo(kol);
	}
	for (int j = 0; j < kol; j++)
	{
		dogy[j]->vivod();
		cout << "\n";
	}
	for (int j = 0; j < kol; j++)
	{
		sum = dogy[j]->add_price(sum);
	}
	cout << "После кормления:" << endl;
	for (int j = 0; j < kol; j++)
	{
		dogy[j]->kormlenie();
		if (j + 1 != kol)
		{
			dogy[j + 1]->set_rasxodi(dogy[j]->get_rasxodi());
		}
		dogy[j]->getname();
		dogy[j]->getves();
		cout << endl;
	}
	for (int j = 0; j < kol; j++)
	{
		dogy[j]->set_rasxodi(dogy[kol - 1]->get_rasxodi());
	}
	dogy[kol - 1]->read();
	cout << "После продажи:" << endl;
	for (int j = 0; j < kol; j++)
	{
		dogy[j]->prodaja();
		if (j + 1 != kol)
		{
			dogy[j + 1]->set_rasxodi(dogy[j]->get_rasxodi());
			dogy[j + 1]->set_pribil(dogy[j]->get_pribil());
			dogy[j + 1]->set_kolvo(dogy[j]->get_kolvo());
		}
	}
	dogy[kol - 1]->read();
	delete[] dogy;
	return 0;
}


