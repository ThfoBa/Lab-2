// Разработка программного модуля, описывающего работу питомника для собак (структуры языка C) 
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
	check.dogs.age = a;
	check.dogs.ves = v;
	check.dogs.health = h;
	check.dogs.price = pr;
	check.price_korm = 15;
	return check;
}
