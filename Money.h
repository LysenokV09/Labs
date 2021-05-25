#pragma once
#include <iostream>
using namespace std;

class Money
{
	long Rubles;														// Рубли
	int Penny;															// Копейки
public:
	Money();															// Конструктор без параметров
	Money(long Rubs, int Pens);											// Конструктор с параметрами
	Money(const Money& Pointer);										// Конструктор копирования
	~Money();															// Деструктор
	Money& operator = (const Money& Link);								// Оператор присваивания
	Money& operator + (const Money& el);								// Оператор сложения
	friend istream& operator >> (istream& in, Money& Pointer);			// Оператор ввода
	friend ostream& operator << (ostream& out, const Money& Pointer);	// Оператор вывода
};
