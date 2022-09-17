﻿// Разработка программного модуля, описывающего работу питомника для собак (структуры языка C) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#define LN 100
#define default_pets_name "no_name"

typedef struct {
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
	int price_korm;
	pets dogs;
}pitomnik;

pitomnik initialization(int k, double p, double r, int a, int v, int h, int pr)
{
	pitomnik check; // вспомогательная переменная
	check.kolvo = k;
	check.pribil = p;
	check.rasxodi = r;
	check.price_korm = 15;
	strcpy_s(check.dogs.name, default_pets_name);
	check.dogs.age = a;
	check.dogs.ves = v;
	check.dogs.health = h;
	check.dogs.price = pr;
	return check;
}

pitomnik vvod()
{
	pitomnik tmp;
	tmp = initialization(0, 0, 0, 0, 0, 0, 0);
	printf("Введите имя животного: \n");
	rewind(stdin);
	gets_s(tmp.dogs.name, LN);
	printf("Введите возраст животного (кол-во полных месяцев): \n");
	scanf_s("%d", &tmp.dogs.age);
	printf("Введите вес животного (в граммах): \n");
	scanf_s("%d", &tmp.dogs.ves);
	printf("Введите состояние здоровья животного (от 1 до 10): \n");
	scanf_s("%d", &tmp.dogs.health);
	printf("Введите стоимость животного: \n");
	scanf_s("%lf", &tmp.dogs.price);
	tmp.kolvo++;
	return tmp;
}

void add_price(pitomnik dog1, pitomnik dog2)
{
	double sum;
	sum = dog1.dogs.price + dog2.dogs.price;
	printf("Итоговая стоимость животных: %lf руб.\n", sum);
}

void vivod(pitomnik tmp)
{
	printf("Количество животных: %d шт.\n", tmp.kolvo);
	printf("Прибыль питомника: %lf руб.\n", tmp.pribil);
	printf("Расходы питомника: %lf руб.\n", tmp.rasxodi);
	printf("Стоимость корма: %d руб.\n", tmp.price_korm);
	printf("Имя животного: %s\n", tmp.dogs.name);
	printf("Возраст животного: %d мес.\n", tmp.dogs.age);
	printf("Вес животного: %d гр.\n", tmp.dogs.ves);
	printf("Состояние здоровья животного: %d\n", tmp.dogs.health);
	printf("Стоимость животного: %lf руб.\n", tmp.dogs.price);
}
pitomnik kormlenie(pitomnik tmp)
{
	tmp.dogs.ves += 1;
	tmp.rasxodi = tmp.rasxodi + (tmp.price_korm * tmp.kolvo);
	printf("Животные накормлены!\n");
	return tmp;
}
pitomnik prodaja(pitomnik tmp)
{
	tmp.kolvo -= 1;
	tmp.pribil += tmp.dogs.price;
	tmp.rasxodi -= (tmp.price_korm * tmp.kolvo);
	strcpy_s(tmp.dogs.name, default_pets_name);
	tmp.dogs.age = 0;
	tmp.dogs.ves = 0;
	tmp.dogs.health = 0;
	tmp.dogs.price = 0;
	printf("Животное продано!\n");
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	pitomnik tmp;
	int kolvo = 0;
	tmp = initialization(kolvo, 0, 0, 0, 0, 0, 0);
	printf("Инициализация: \n");
	vivod(tmp);
	tmp = vvod();
	printf("\nПосле ввода: \n");
	vivod(tmp);
	tmp = kormlenie(tmp);
	printf("\nПосле кормления: \n");
	vivod(tmp);
	tmp = prodaja(tmp);
	printf("\n После продажи: \n");
	vivod(tmp);
	pitomnik dog1;
	dog1 = vvod();
	add_price(tmp, dog1);
	pitomnik* c = (pitomnik*)malloc(LN * sizeof(pitomnik));
	printf("\nРабота с динамическими переменными:\n");
	*c = initialization(kolvo, 0, 0, 0, 0, 0, 0);
	printf("\nИнициализация: \n");
	vivod(*c);
	*c = vvod();
	printf("\nПосле ввода: \n");
	vivod(*c);
	*c = kormlenie(*c);
	printf("\nПосле кормления:\n");
	vivod(*c);
	*c = prodaja(*c);
	printf("\nПосле продажи:\n");
	vivod(*c);
	pitomnik* c1 = (pitomnik*)malloc(LN * sizeof(pitomnik));
	*c1 = vvod();
	add_price(*c, *c1);
	printf("\nАдреса динамических переменных:\n");
	printf("%p", c);
	return 0;
}

	
	

		
