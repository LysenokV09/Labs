#include "Money1.h"
#include <iostream>
using namespace std;
Money::Money(long int rubs, int kops)
{
	double sum1 = kops;
	sum1 = sum1 / 100;
	sum1 = sum1 + rubs;
	sum = sum1;
}

void Money::Print(double s)
{
	cout << "Рубли с копейками = " << s << endl;
}