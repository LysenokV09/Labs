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
	cout << "\n����� ���������...\n";
	cout << "���: " << Name << endl;
	cout << "�������: " << Age << endl << endl;
}

void People::Input()
{
	cout << "\n���� ������...\n\n";
	cout << "������� ���: ";
	cin >> Name;
	cout << "������� �������: ";
	cin >> Age;
	while (Age <= 0)
	{
		cout << "������: ������� �� ����� ���� �������������. ������� ����� �������: ";
		cin >> Age;
	}
	cout << endl;
}