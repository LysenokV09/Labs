#include "People.h"
#include <iostream>
using namespace std;

People::People()
{
	Name = "";
	Age = 0;
}

People::People(string name, int age)
{
	Name = name;
	Age = age;
}

People::People(const People& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
}

People::~People()
{

}

People& People::operator =(const People& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
	}
	return *this;
}

void People::Show()
{
	cout << "\nВывод атрибутов...\n";
	cout << "Имя: " << Name << endl;
	cout << "Возраст: " << Age << endl << endl;
}

void People::Input()
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
	cout << endl;
}