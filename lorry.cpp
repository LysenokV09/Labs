#include "lorry.h"
//����������� ��� ���������� 
Lorry::Lorry(void):Car()
{
gipot = 0;
gipot1 = 0;
}
//��������� 
Lorry::~Lorry(void)
{
}
//����������� � �����������
Lorry::Lorry( int C, int P, double G) :Car(C, P,G)
{
	gipot = G;
}
//����������� ����������� 
Lorry::Lorry(const Lorry &L)
{
	 first = L.first; second = L.second; gipot = L.gipot;
}
//�����������
void Lorry::Set_Gruz(double G)
{
	gipot = G;
}

//������� ������������
Lorry& Lorry::operator=(const Lorry& l)
{
	if (&l == this)return *this; 
	second = l.second; 
	first = l.first;
	gipot = sqrt((l.first * l.first) + (l.second * l.second));
	return *this;
}
//�������� �����
istream& operator>>(istream& in, Lorry& l)
{
	
	 cout << "\n������ �����: "; 
	 in >> l.first; 
	 cout << "������ �����: "; 
	 in >> l.second; 
	 l.gipot = l.first*l.second;
	 l.gipot1 = l.first - l.second;
	 return in;
}
//�������� ������
ostream& operator<<(ostream& out, const Lorry& l)
{
	out << "\n������ ����� : " << l.first; out << "\n������ ����� : " << l.second; 
	out << "\n������������ : " << l.gipot; out << "\n�������� : " << l.gipot1;
	 out << "\n";
	return out;
}
