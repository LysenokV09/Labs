#include "car.h"
#include "object.h"
Car::Car(void)
{
	first = 0;
	second = 0;
}
Car::~Car(void)
{
}
Car::Car(int C, int P, int M)
{
	first = C;
	second = P;
	multiply = M;
}
Car::Car(const Car& car)
{
	first = car.first;
	second = car.second;
}
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
Car& Car::operator=(const Car& c)
{
	if (&c == this)return *this;
	second = c.first;
	first = c.second;
	multiply = c.first * c.second;
	return *this;
}
istream& operator>>(istream& in, Car& c)
{
	cout << "Первое число: ";
	in >> c.first;
	cout << "Второе число:";
	in >> c.second;
	return in;
}
/*ostream& operator<<(ostream& out, const Car& c)
{
	out << "\nПервое число: " << c.first; 
	out << "\nВторое число: " << c.second; 
	out << "\nПроизведение0: " << c.first * c.second;
	out << "\n";
	return out;
}*/
void Car::Show() {
	cout << "\nПервое число: "<<first;
	cout << "\nВторое число:"<<second;
	cout << "\nСумма: " << first + second;
	cout << "\n";
}