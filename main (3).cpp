#include "Object.h" 
#include "Car.h" 
#include "Lorry.h" 
#include "Vector.h"
#include <string> 
#include <iostream> 
using namespace std; 
void main()
{
	setlocale(LC_ALL, "RUS");
Vector v(5);
Car a;
cin >> a;
Object* p =&a;
v.Add(p);
Lorry b;
cin >> b;
p = &b;
v.Add(p);
cout<<v;
}
