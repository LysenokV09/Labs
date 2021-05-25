#include "pair.h"
//конструктор без параметров 
Car::Car(void)
{
first = 0;
second = 0;
}
//деструктор 
Car::~Car(void)
{
}
//конструктор с параметрами 
Car::Car(int C,int P, int M)
{
	first = C; 
	second = P;
	multiply = M;
}
//конструктор копирования 
Car::Car(const Car& car)
{
	first = car.first; 
	second = car.second;
}
//модификаторы
void Car::Set_first(int C)
{
	first = C;
}
void Car::Set_second(int P)
{
	second = P;
}
void Car::Set_mult(int M)
{
	multiply = M;
}
//перегрузка операции присваивания 
Car& Car::operator=(const Car&c)
{
	if (&c == this)return *this; 
	second = c.first; 
	first = c.second;
	multiply = c.first * c.second;
	return *this;
}
//глобальная функция для ввода 
istream& operator>>(istream&in,Car&c)
{ 
	cout << "Первое число: "; 
	in >> c.first; 
	cout << "Второе число: "; 
	in >> c.second; 
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Car& c)
{
	out << "\nПервое число: " << c.first; out << "\nВторое число: " << c.second; out << "\nСумма: " << c.first + c.second;
	out << "\n";
	return out;
}
