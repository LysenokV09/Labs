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
		cout << "\nВыберите класс нового объекта:\n\n";
		cout << "1. Класс People\n";
		cout << "2. Класс Student\n";
		cout << "\nВведите номер операции: ";
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
				cout << "\nОшибка: введен неверный номер. Элемент не может быть добавлен...\n\n";
			}
		}
	}
	else
	{
		cout << "\nВы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n\n";
	}
}

void List::Show()
{
	if (Size > 0)
	{
		if (Beg[0] == nullptr)
		{
			cout << "\nМножество не заполнено...\n\n";
		}
		else
		{
			cout << "\nВывожу элементы дерева...\n\n";
			Object** ptr = Beg;
			int i = 0;
			while (i < Size)
			{
				cout << "Объект № " << i + 1 << endl;
				if (*ptr != nullptr)
				{
					(*ptr)->Show();
				}
				else
				{
					cout << "\nОбъект пуст!\n\n";
				}
				ptr++;
				i++;
			}
		}
	}
	else
	{
		cout << "\nВы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n\n";
	}
}

void List::Elem(int Index)
{
	if (Size > 0)
	{
		if (Index >= Size)
		{
			cout << "\nИндекс за пределами размерности дерева!\n\n";
		}
		else
		{
			Object* ptr = Beg[Index];
			if (ptr != nullptr)
			{
				cout << "\nВывожу данные элемента с индексом " << Index << endl << endl;
				ptr->Show();
			}
			else
			{
				cout << "\nЭлемента под данным индексом не существует. Заполните данный элемент!\n\n";
			}
		}
	}
	else
	{
		cout << "Вы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n";
	}
}

int List::operator () ()
{
	return Size;
}

void List::Del()			// "Удаление", память не освобождается!
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
		cout << "Удаление невозможно: размер группы равен 0 или группа не создана\n";
		Size = 0;
	}
}
