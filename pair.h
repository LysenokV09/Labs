#pragma once 
#include <string> 
#include <iostream> 
using namespace std; 
class Car
{
//����������� ��� ���������� 
public:
Car(void); 
public:
virtual ~Car(void);
Car(const Car&);
Car(int C, int P, int M);
	//���������
int Get_cyl() { 
	return first; 
}
int Get_power() { 
	return second; 
}
int Get_mult() {
	return multiply;
}
	//������������
void Set_first(int); 
void Set_second(int);
void Set_mult(int);
	//���������� �������� ������������ 
	Car& operator=(const Car&);
	//���������� ���������-������� �����-������
friend istream& operator>>(istream& in, Car& c); 
friend ostream& operator<<(ostream& out, const Car& c);
	//�������� 
protected:
int first;
int second;
int multiply;
};
