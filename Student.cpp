#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : People()
{
	Rating = 0;
}

Student::Student(string name, int age, int rating) : People(name, age)
{
	Rating = rating;
}

Student::Student(const Student& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
	Rating = Ptr.Rating;
}

Student::~Student()
{

}

Student& Student::operator =(const Student& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
		Rating = Ptr.Rating;
	}
	return *this;
}

void Student::Show()
{
	cout << "\nВывод информации...\n";
	cout << "Имя: " << Name << endl;
	cout << "Возраст: " << Age << endl;
	cout << "Группа: " << gr << endl;
	cout << "Рейтинг: " << Rating << endl << endl;;
}

void Student::Input()
{
	cout << "\nВвод данных...\n\n";
	cout << "Введите имя: ";
	cin >> Name;
	cout << "Введите возраст: ";
	cin >> Age;
	while (Age <= 0)
	{
		cout << "Ошибка: возраст не может быть отрицательным. Введите новый возраст: ";
		cin >> Age;
	}
	cout << "Введите рейтинг: ";
	cin >> Rating;
	while (Rating <= 0)
	{
		cout << "Ошибка: рейтинг не может быть отрицательным. Введите новый рейтинг: ";
		cin >> Rating;
	}
	cout << "Введите группу: ";
	cin >> gr;
	
	cout << endl;
}