#include <iostream> 
#include "pair.h" 
#include "lorry.h"
using namespace std; 
void f1(Car& c)
{
	cout << c;
}
//функция возвращает объект базового класса как результат 

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
Lorry c;//создать объект 
cin>>c;//ввести значения атрибутов 
f1(c);//передаем объект класса Lorry 
cout<<c;//вывести значения атрибутов
}
