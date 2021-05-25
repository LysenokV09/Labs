#include"Plenty.h"

//����������� � �����������
Plenty::Plenty(int s, int k)
{
	size = s;
	data = new int[size]; 
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.el = &data[0]; 
	end.el = &data[size];
}
//����������� �����������
Plenty::Plenty(const Plenty& a)
{
	size = a.size; 
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg; end = a.end;
}
//����������
Plenty::~Plenty()
{
	delete[]data; data = 0;

}
//�������� ������������
Plenty& Plenty::operator=(const Plenty& a) {
	if (this == &a)return *this; size = a.size;
	if (data != 0) delete[]data; data = new int[size]; for (int i = 0; i < size; i++)
		data[i] = a.data[i];

	beg = a.beg; 
	end = a.end; 
	return *this;
}
//�������� ������� �� ������� 
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
//�������� ��� ���������� ��������� 
Plenty Plenty::operator+(const int k)//+k
{
	Plenty temp(size);
	for (int i = 0; i < size; ++i) {
		temp.data[i] += data[i] + k;
	}
	return temp;
}
//�������� ��� ��������� ����� �������
int Plenty::operator()()
{
	/*int len = 5;*/
	return size;
}

istream& operator >>(istream& in, Plenty& el)							// �������� �����
{
	for (int i = 0; i < el.size; ++i)
	{
		cout << "������� ������ " << i + 1 << " ������� � ������\n";
		in >> el.data[i];
	}
	return in;
}
ostream& operator <<(ostream& out, const Plenty& el)					// �������� ������
{
	cout << "����� ������ �� ������\n";
	for (int i = 0; i < el.size; ++i)
	{
		out << el.data[i] << " ";
	}
	return out;
}
