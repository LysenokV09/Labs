#include "List.h"
#include "People.h"
#include "Student.h"
#include <iostream>
using namespace std;

List::List()
{
	Beg = 0;
	Cur = 0;
	Size = 0;
}

List::List(int N)
{
	Beg = new Object * [N];
	Object* ptr = nullptr;
	for (int i = 0; i < N; i++)
	{
		Beg[i] = ptr;
	}
	Cur = 0;
	Size = N;
}

List::~List()
{
	if (Beg != 0)
	{
		delete[] Beg;
	}
	Beg = 0;
}

void List::Add()
{
	if (Size > 0)
	{
		Object* ptr;
		cout << "\n�������� ����� ������ �������:\n\n";
		cout << "1. ����� People\n";
		cout << "2. ����� Student\n";
		cout << "\n������� ����� ��������: ";
		int Code;
		cin >> Code;
		if (Code == 1)
		{
			People* elem1 = new (People);
			elem1->Input();
			ptr = elem1;
			if (Cur < Size)
			{
				Beg[Cur] = ptr;
				Cur++;
			}
			else
			{
				Size++;
				Beg[Cur] = ptr;
				Cur++;
			}
			cin.ignore();
		}
		else
		{
			if (Code == 2)
			{
				Student* elem2 = new Student;
				elem2->Input();
				ptr = elem2;
				if (Cur < Size)
				{
					Beg[Cur] = ptr;
					Cur++;
				}
				else
				{
					Size++;
					Beg[Cur] = ptr;
					Cur++;
				}
				cin.ignore();
			}
			else
			{
				cout << "\n������: ������ �������� �����. ������� �� ����� ���� ��������...\n\n";
			}
		}
	}
	else
	{
		cout << "\n�� �� ������� ������! ��������� ������� m �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n\n";
	}
}

void List::Show()
{
	if (Size > 0)
	{
		if (Beg[0] == nullptr)
		{
			cout << "\n��������� �� ���������...\n\n";
		}
		else
		{
			cout << "\n������ �������� ������...\n\n";
			Object** ptr = Beg;
			int i = 0;
			while (i < Size)
			{
				cout << "������ � " << i + 1 << endl;
				if (*ptr != nullptr)
				{
					(*ptr)->Show();
				}
				else
				{
					cout << "\n������ ����!\n\n";
				}
				ptr++;
				i++;
			}
		}
	}
	else
	{
		cout << "\n�� �� ������� ������! ��������� ������� m �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n\n";
	}
}

void List::Elem(int Index)
{
	if (Size > 0)
	{
		if (Index >= Size)
		{
			cout << "\n������ �� ��������� ����������� ������!\n\n";
		}
		else
		{
			Object* ptr = Beg[Index];
			if (ptr != nullptr)
			{
				cout << "\n������ ������ �������� � �������� " << Index << endl << endl;
				ptr->Show();
			}
			else
			{
				cout << "\n�������� ��� ������ �������� �� ����������. ��������� ������ �������!\n\n";
			}
		}
	}
	else
	{
		cout << "�� �� ������� ������! ��������� ������� m �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n";
	}
}

int List::operator () ()
{
	return Size;
}

void List::Del()			// "��������", ������ �� �������������!
{
	if (Size > 0)
	{
		int temp = Size - 1;
		while (Beg[temp] == nullptr)
		{
			Size--;
			temp--;
		}
		Size--;
		Cur--;
	}
	else
	{
		cout << "�������� ����������: ������ ������ ����� 0 ��� ������ �� �������\n";
		Size = 0;
	}
}
