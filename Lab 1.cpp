// Разработка программного модуля, описывающего работу питомника для собак (структуры языка C) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define LN 100
#define default_pets_name "Дружок"

typedef struct {
	int id; 
	char name[LN];
	int age;
	int ves;
	int health;
	double price;
}pets;

typedef struct {
	int kolvo;
	double pribil;
	double rasxodi;
	double pribil_chistaya;
	int price_korm;
	pets dogs[LN];
}pitomnik;


pitomnik initialization(int k, double p,double pchist, double r,int id, int a, int v, int h, int pr)
{
	pitomnik check; 
	check.kolvo = k;
	check.pribil = p;
	check.rasxodi = r;
	check.pribil_chistaya = pchist;
	check.price_korm = 15;
	for (int i = 0; i < k; i++)
	{
		check.dogs[i].id = id;
		strcpy_s(check.dogs[i].name, default_pets_name);
		check.dogs[i].age = a;
		check.dogs[i].ves = v;
		check.dogs[i].health = h;
		check.dogs[i].price = pr;
	}
	return check;
}
pitomnik vvod()
{
	pitomnik tmp;
	int kol;
	tmp = initialization(1, 0, 0, 0, 27, 23, 2000, 10,999);
	printf("Введите количество животных, которых требуется добавить: \n");
	scanf_s("%d", &kol);
	for (int i = 1; i <= kol; i++)
	{
		printf("\nID: \n");
		scanf_s("%d", &tmp.dogs[i].id);
		printf("Введите имя животного: \n");
		rewind(stdin);
		gets_s(tmp.dogs[i].name, LN);
		printf("Введите возраст животного (кол-во полных месяцев): \n");
		scanf_s("%d", &tmp.dogs[i].age);
		printf("Введите вес животного (в граммах): \n");
		scanf_s("%d", &tmp.dogs[i].ves);
		printf("Введите состояние здоровья животного (от 1 до 10): \n");
		scanf_s("%d", &tmp.dogs[i].health);
		printf("Введите стоимость животного: \n");
		scanf_s("%lf", &tmp.dogs[i].price);
	}
	tmp.kolvo += kol;
	return tmp;
}
void add_price(pitomnik tmp)
{
	double sum = 0;
	for (int i = 0; i < (tmp.kolvo); i++)
	{
		sum += tmp.dogs[i].price;
	}
	printf("Итоговая стоимость животных: %lf руб.\n", sum);
}
double pribil_chistaya(pitomnik tmp)
{
	double pribil_chist = 0;
	pribil_chist = (tmp.pribil) - (tmp.rasxodi);
	return pribil_chist;
}
double pribil(pitomnik tmp,int k)
{
	double pribil = 0;
	pribil += tmp.dogs[k].price;
	return pribil;
}
int numofdogtosell(pitomnik tmp,int id)
{
	int k = 0;
	for (int i = 0; i < (tmp.kolvo); i++)
	{
		if (id == (tmp.dogs[i].id))
		{
			k = i;
			break;
		}
	}
	return k;
}	
void vivod(pitomnik tmp)
{

	printf("Количество животных: %d шт.\n", tmp.kolvo);
	printf("Прибыль питомника (грязная): %lf руб.\n", tmp.pribil);
	printf("Расходы питомника: %lf руб.\n", tmp.rasxodi);
	printf("Чистая прибыль питомника: %lf руб.\n", tmp.pribil_chistaya);
	printf("Стоимость корма: %d руб.\n", tmp.price_korm);
	for (int i = 0; i < (tmp.kolvo); i++)
	{
		printf("\nID: %d\n", tmp.dogs[i].id);
		printf("Имя животного: %s\n", tmp.dogs[i].name);
		printf("Возраст животного: %d мес.\n", tmp.dogs[i].age);
		printf("Вес животного: %d гр.\n", tmp.dogs[i].ves);
		printf("Состояние здоровья животного: %d\n", tmp.dogs[i].health);
		printf("Стоимость животного: %lf руб.\n", tmp.dogs[i].price);
	}
}
pitomnik kormlenie(pitomnik tmp)
{
	for (int i = 0; i < tmp.kolvo; i++)
	{
		tmp.dogs[i].ves += 1;
	}
	tmp.rasxodi = tmp.rasxodi + (tmp.price_korm * tmp.kolvo);
	printf("Животные накормлены!\n");
	return tmp;
}
pitomnik prodaja(pitomnik tmp)
{
	int i,id,k=0;
	printf("Введите ID животного, которое требуется продать: ");
	scanf_s("%d", &id);
	k = numofdogtosell(tmp, id);
	tmp.pribil = pribil(tmp,k);
	tmp.pribil_chistaya = pribil_chistaya(tmp);
	if ((k != 0) && (k != ((tmp.kolvo) - 1)) && (id == (tmp.dogs[k].id)))
	{
		for (int i = k; i < ((tmp.kolvo) - 1); i++)
		{
			tmp.dogs[i] = tmp.dogs[i + 1];
		}
	}
	else if ((k == 0) && (id == (tmp.dogs[k].id)))
	{
		for (int i = 0; i < ((tmp.kolvo) - 1); i++)
		{
			tmp.dogs[i] = tmp.dogs[i + 1];
		}
	}
	else if ((id == (tmp.dogs[k].id))&& (k == (tmp.kolvo)))
	{
		tmp.kolvo -= 1;
	}
	tmp.kolvo -= 1;
	printf("Животное продано!\n");
	return tmp;
}
int main()
{
	setlocale(LC_ALL, "rus");
	pitomnik tmp;
	char l;
	do {
		tmp = initialization(1, 0, 0, 0, 27, 23, 2000, 10, 999);
		vivod(tmp);
		tmp = vvod();
		printf("\nПосле ввода: \n");
		vivod(tmp);
		add_price(tmp);
		tmp = kormlenie(tmp);
		printf("\nПосле кормления: \n");
		vivod(tmp);
		tmp = prodaja(tmp);
		printf("\n После продажи: \n");
		vivod(tmp);
		add_price(tmp);
		printf("Для повтора программы нажмите любую клавишу.\n");
		printf("Для выхода из программы нажмите ESC.\n");
		l = _getch();
		system("cls");
	} while (l != 27);
	return 0;
}

	
	





	
	
	
	


		

		


	
	

		
