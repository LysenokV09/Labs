#pragma once 
#include <string> 
#include <iostream> 
using namespace std; 
class Car
{
//конструктор без параметров 
public:
Car(void); 
public:
virtual ~Car(void);
Car(const Car&);
Car(int C, int P, int M);
	//селекторы
int Get_cyl() { 
	return first; 
}
int Get_power() { 
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
protected:
int first;
int second;
int multiply;
};
