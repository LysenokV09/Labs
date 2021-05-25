#include"Plenty.h"

//конструктор с параметрами
Plenty::Plenty(int s, int k)
{
	size = s;
	data = new int[size]; 
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.el = &data[0]; 
	end.el = &data[size];
}
//конструктор копирования
Plenty::Plenty(const Plenty& a)
{
	size = a.size; 
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg; end = a.end;
}
//деструктор
Plenty::~Plenty()
{
	delete[]data; data = 0;

}
//операция присваивания
Plenty& Plenty::operator=(const Plenty& a) {
	if (this == &a)return *this; size = a.size;
	if (data != 0) delete[]data; data = new int[size]; for (int i = 0; i < size; i++)
		data[i] = a.data[i];

	beg = a.beg; 
	end = a.end; 
	return *this;
}
//операция доступа по индексу 
int& Plenty::operator [](int index)
{
	if (index < size)
	{
		return data[index];
	}
	else {
		cout << "\nError! Index>size";
	}
}
//операция для добавления константы 
Plenty Plenty::operator+(const int k)//+k
{
	Plenty temp(size);
	for (int i = 0; i < size; ++i) {
		temp.data[i] += data[i] + k;
	}
	return temp;
}
//операция для получения длины вектора
int Plenty::operator()()
{
	/*int len = 5;*/
	return size;
}

istream& operator >>(istream& in, Plenty& el)							// Операция ввода
{
	for (int i = 0; i < el.size; ++i)
	{
		cout << "Введите данные " << i + 1 << " объекта в список\n";
		in >> el.data[i];
	}
	return in;
}
ostream& operator <<(ostream& out, const Plenty& el)					// Операция вывода
{
	cout << "Вывод данных из списка\n";
	for (int i = 0; i < el.size; ++i)
	{
		out << el.data[i] << " ";
	}
	return out;
}
