#pragma once 
#include "pair.h"

//класс Lorry наследуется от класса Car 
class Lorry :
public Car
{
public:
Lorry(void);
//конструктор без параметров 
public:
~Lorry(void);
//деструктор 
Lorry(int,int,double);
//конструктор с параметрами 
Lorry(const Lorry & );
//конструктор копирования
int Get_gruz() { 
	return gipot; 
}
//модификатор 
void Set_Gruz(double);
//селектор
Lorry& operator=(const Lorry&);
//операция присваивания
friend istream& operator>>(istream& in,Lorry& l);
//операция ввода
friend ostream& operator<<(ostream& out,const Lorry& l); 
//операция вывода protected:
double gipot,gipot1;
//атрибут грузоподъемность

};


