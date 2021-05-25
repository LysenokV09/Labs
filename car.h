#pragma once
#include "object.h" 
#include <string> 
#include <iostream> 
using namespace std;
class Car: 
	public Object
{
	
protected:
	int first;
	int second;
	int multiply;
public:
	Car(void);
public:
	virtual ~Car(void);
	void Show();
	Car(int, int, int);
	Car(const Car&);
	int Get_first() {
		return first;
	}
	int Get_second() {
		return second;
	}
	int Get_mult() {
		return multiply;
	}
	//модификаторы
	void Set_first(int);
	void Set_second(int);
	void Set_mult(int);
	//перегрузка операции присваивания 
	Car& operator=(const Car&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Car& c);
	friend ostream& operator<<(ostream& out, const Car& c);
	//атрибуты 

};

