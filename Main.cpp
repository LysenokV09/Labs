#include <iostream> 
#include "pair.h" 
#include "lorry.h"
using namespace std; 
void f1(Car& c)
{
	cout << c;
}
//������� ���������� ������ �������� ������ ��� ��������� 

void main()
{
	setlocale(LC_ALL, "RUS");
Car a; 
cin >> a;
cout << a;
/*Car b(12, 13, 17.6918); 
cout << b;
a = b; 
cout << a;*/
Lorry c;//������� ������ 
cin>>c;//������ �������� ��������� 
f1(c);//�������� ������ ������ Lorry 
cout<<c;//������� �������� ���������
}
