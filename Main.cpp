#include "Money1.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	long int rub = -1;
	int kop = -1;
	while (rub < 1)
	{
		cout << "Введи количество рублей: "; cin >> rub;
	}

	while (kop < 0 || kop >99)
	{
		cout << "Введи количество копеек: "; cin >> kop;
	}
	Money a(rub, kop);
	a.Print(a.sum);

	rub = -1; kop = -1;

	while (rub < 1)
	{
		cout << endl << "Введи количество рублей: "; cin >> rub;
	}

	while (kop < 0 || kop >99)
	{
		cout << "Введи количество копеек: "; cin >> kop;
	}
	Money b(rub, kop);
	b.Print(b.sum);

	cout.precision(3);
	cout << endl << "Общая сумма денежных средств: " << a.sum + b.sum;
	
	cout << endl << "Разность денежных средств: " << a.sum - b.sum;
/*	double k;
	cout << endl << "Введи число, на которое будут умноженны суммы: "; cin >> k;

	a.sum = a.sum * k;
	b.sum = b.sum * k;
	a.Print(a.sum);
	b.Print(b.sum);*/
}