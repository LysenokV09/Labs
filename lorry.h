#pragma once 
#include "pair.h"

//����� Lorry ����������� �� ������ Car 
class Lorry :
public Car
{
public:
Lorry(void);
//����������� ��� ���������� 
public:
~Lorry(void);
//���������� 
Lorry(int,int,double);
//����������� � ����������� 
Lorry(const Lorry & );
//����������� �����������
int Get_gruz() { 
	return gipot; 
}
//����������� 
void Set_Gruz(double);
//��������
Lorry& operator=(const Lorry&);
//�������� ������������
friend istream& operator>>(istream& in,Lorry& l);
//�������� �����
friend ostream& operator<<(ostream& out,const Lorry& l); 
//�������� ������ protected:
double gipot,gipot1;
//������� ����������������

};


