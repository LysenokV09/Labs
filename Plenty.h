#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class List;													// ������������� �����
																// ��������� �� ������� ���� int
public:
	int* el;
	Iterator() { el = 0; }											// ����������� ��� ����������
	Iterator(const Iterator& it) { el = it.el; }					// ����������� �����������
	bool operator ==(const Iterator& it) { return (el == it.el); }	// �������� ���������
	bool operator !=(const Iterator& it) { return (el != it.el); }	// �������� ���������
	void operator ++() { ++el; }										// ���������
	void operator --() { --el; }										// ��������� 
	void operator -=(int N) { el -= N; }								// ������� �� N ��������� �����
	int& operator *() const { return *el; }							// ���������������
};

class Plenty
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	Plenty(int s, int k = 0);
	//����������� � �����������
	 Plenty(const Plenty&a);
	//����������
	~Plenty();
	//�������� ������������ 
	Plenty&operator=(const Plenty&a);
	//�������� ������� �� ������� 
	int&operator[](int index);
	//�������� ��� ���������� ��������� 
	Plenty operator+(const int k);
	//��������, ������������ ����� ������� 
	int operator()();
	//������������� �������� �����-������
friend ostream& operator<<(ostream& out, const Plenty& a); 
friend istream& operator>>(istream& in, Plenty& a); 
Iterator first(){
	return beg; 
}//���������� ��������� �� ������ �������
Iterator last(){
	return end;
}//���������� ��������� �� ������� ��������� ����������� 
private:
	int size; 
	int len;
	int* data;
	Iterator beg;//��������� �� ������ ������� ������� 
	Iterator end;//��������� �� ������� ��������� �� ���������
};
