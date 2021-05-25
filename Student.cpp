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
	cout << "\n����� ����������...\n";
	cout << "���: " << Name << endl;
	cout << "�������: " << Age << endl;
	cout << "������: " << gr << endl;
	cout << "�������: " << Rating << endl << endl;;
}

void Student::Input()
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
	cout << "������� �������: ";
	cin >> Rating;
	while (Rating <= 0)
	{
		cout << "������: ������� �� ����� ���� �������������. ������� ����� �������: ";
		cin >> Rating;
	}
	cout << "������� ������: ";
	cin >> gr;
	
	cout << endl;
}