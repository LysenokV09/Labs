#include <iostream>
#include "MNOG.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int s=-1, in, menu = 4;
	while (s <= 0)
	{
		cout << "����� ���������� ��������� ���������: "; cin >> s;
	}
		
	
	Vector a(s);
	int ind;
	while (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5)
	{
		
		cout << endl << endl << "����: \n\t1. �������� ������� �� ������� \n\t2. �������� ������ ��������� \n\t3. ������� ������� �� �������\n\t 4. ������� ��������� \n\n\t0. �����";
		cout << endl << "������ ����� ����: "; cin >> menu;
		if (menu == 1)
		{
			cout << "����� ������ ��������, ������� ������ ��������, ��������� � 0: "; cin >> in;
			//in = ind + 1;
			try
			{
				cout << "������� �������: " << a.give(in);
			}
			catch (const int in)
			{
				cout << "������ �����";
			}
		}

		if (menu == 2)
			cout << "������ = " << a.givesize();

	/*	if (menu == 3)
			a.cross();
			*/
		if (menu == 3)
		{
			cout << "����� ������ ��������: "; cin >> in;
			try
			{
				a.del(in);
				cout << "������� ������ " << endl;
			}
			catch (const int e)
			{
				cout << "������ �����";
			}
			
		}

		if (menu == 4)
		{
			a.print();
		}

		if (menu == 0)
		{
			a.end();
			break;
		}
	}
}