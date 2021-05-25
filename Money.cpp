#include "Money.h"
#include <iostream>
using namespace std;

Money::Money()												// ����������� ��� ����������
{
	Rubles = 0;
	Penny = 0;
}

Money::Money(long Rubs, int Pens)							// ����������� � �����������
{
	Rubles = Rubs;
	Penny = Pens;
}

Money::Money(const Money& Pointer)							// ����������� �����������
{
	Rubles = Pointer.Rubles;
	Penny = Pointer.Penny;
}

Money::~Money()												// ����������
{

}

Money& Money::operator = (const Money& Link)				// �������� ������������
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

istream& operator >> (istream& in, Money& Pointer)			// �������� �����
{
	cout << "������� ���������� ������: ";
	in >> Pointer.Rubles;
	while (Pointer.Rubles < 0)
	{
		cout << "���������� ������ �� ����� ���� ������������� ������. ������� ����� ����� ������: ";
		in >> Pointer.Rubles;
	}
	cout << "������� ���������� ������: ";
	in >> Pointer.Penny;
	while (Pointer.Penny < 0 || Pointer.Penny > 99)
	{
		cout << "���������� ������ �� ����� ���� ������������� ������ ��� ������ 99."<<endl<<" ������� ����� ����� ������: ";
		in >> Pointer.Penny;
	}
	
	return in;
}

ostream& operator << (ostream& out, const Money& Pointer)	// �������� ������
{
	cout << "����� ����� �����: ";
	return (out << Pointer.Rubles << "," << Pointer.Penny);
}
