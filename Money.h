#pragma once
#include <iostream>
using namespace std;

class Money
{
	long Rubles;														// �����
	int Penny;															// �������
public:
	Money();															// ����������� ��� ����������
	Money(long Rubs, int Pens);											// ����������� � �����������
	Money(const Money& Pointer);										// ����������� �����������
	~Money();															// ����������
	Money& operator = (const Money& Link);								// �������� ������������
	Money& operator + (const Money& el);								// �������� ��������
	friend istream& operator >> (istream& in, Money& Pointer);			// �������� �����
	friend ostream& operator << (ostream& out, const Money& Pointer);	// �������� ������
};
