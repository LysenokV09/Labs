#include "Classr.h"
#include <iostream>
using namespace std;
Pair::Pair(long int rubs, int kops)
{
	double sum1 = kops;
	sum1 = sum1 / 100;
	sum1 = sum1 + rubs;
	sum = sum1;
}

void Pair::Print(double s)
{
	cout << "Рубли с копейками = " << s << endl;
}