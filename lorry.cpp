#include "lorry.h"
//конструктор без параметров 
Lorry::Lorry(void):Car()
{
gipot = 0;
gipot1 = 0;
}
//дестрктор 
Lorry::~Lorry(void)
{
}
//конструктор с параметрами
Lorry::Lorry( int C, int P, double G) :Car(C, P,G)
{
	gipot = G;
}
//конструктор копирования 
Lorry::Lorry(const Lorry &L)
{
	 first = L.first; second = L.second; gipot = L.gipot;
}
//модификатор
void Lorry::Set_Gruz(double G)
{
	gipot = G;
}

//оперция присваивания
Lorry& Lorry::operator=(const Lorry& l)
{
	if (&l == this)return *this; 
	second = l.second; 
	first = l.first;
	gipot = sqrt((l.first * l.first) + (l.second * l.second));
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Lorry& l)
{
	
	 cout << "\nПервое число: "; 
	 in >> l.first; 
	 cout << "Второе число: "; 
	 in >> l.second; 
	 l.gipot = l.first*l.second;
	 l.gipot1 = l.first - l.second;
	 return in;
}
//операция вывода
ostream& operator<<(ostream& out, const Lorry& l)
{
	out << "\nПервое число : " << l.first; out << "\nВторое число : " << l.second; 
	out << "\nПроизведение : " << l.gipot; out << "\nРазность : " << l.gipot1;
	 out << "\n";
	return out;
}
