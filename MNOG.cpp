#include "MNOG.h"
#include <iostream>
using namespace std;
Vector::Vector(int s)
{
	int k;
	size = s;
	data = new int[size];
	cout << "¬веди элементы множества" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}
}

void Vector::print()
{
	cout << "Ёлементы множества: ";
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

int Vector::give(int index)
{
	if (index < 0 || index >= size)
		throw index;
	return data[index];
}

int Vector::givesize()
{
	return size;
}

void Vector::cross()
{
	int k = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (data[i] == data[j])
				k++;
		}
		if (k != 0)
			cout << "\nЁлемент " << data[i] << " встречаетс€ " << k + 1 << " раз";
		k = 0;
	}
		
}

void Vector::end()
{
	delete [] data;
	data = 0;
}

void Vector::del(int in)
{
	if (in < 0 || in > size)
		throw in;
	data1 = new int[size - 1];
	for (int i = 0; i < in; i++)
	{
		data1[i] = data[i];
	}
	for (int i = in + 1; i < size; i++)
	{
		data1[i - 1] = data[i];
	}
	delete[] data;
	data = data1;
	size--;
}