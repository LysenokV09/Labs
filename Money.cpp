#include "Money.h"
#include <iostream>
using namespace std;

Money::Money()												// Конструктор без параметров
{
	Rubles = 0;
	Penny = 0;
}

Money::Money(long Rubs, int Pens)							// Конструктор с параметрами
{
	Rubles = Rubs;
	Penny = Pens;
}

Money::Money(const Money& Pointer)							// Конструктор копирования
{
	Rubles = Pointer.Rubles;
	Penny = Pointer.Penny;
}

Money::~Money()												// Деструктор
{

}

Money& Money::operator = (const Money& Link)				// Оператор присваивания
{
	if (&Link != this)
	{
		Rubles = Link.Rubles;
		Penny = Link.Penny;
	}
	return *this;
}

Money& Money::operator + (const Money& el)
{
	Penny += el.Penny;
	Rubles = Rubles + el.Rubles + Penny / 100;
	Penny = Penny % 100;
	return *this;
}

istream& operator >> (istream& in, Money& Pointer)			// Оператор ввода
{
	cout << "Введите количество рублей: ";
	in >> Pointer.Rubles;
	while (Pointer.Rubles < 0)
	{
		cout << "Количество рублей не может быть отрицательным числом. Введите новое число рублей: ";
		in >> Pointer.Rubles;
	}
	cout << "Введите количество копеек: ";
	in >> Pointer.Penny;
	while (Pointer.Penny < 0 || Pointer.Penny > 99)
	{
		cout << "Количество копеек не может быть отрицательным числом или больше 99."<<endl<<" Введите новое число копеек: ";
		in >> Pointer.Penny;
	}
	
	return in;
}

ostream& operator << (ostream& out, const Money& Pointer)	// Оператор вывода
{
	cout << "Общая сумма денег: ";
	return (out << Pointer.Rubles << "," << Pointer.Penny);
}
