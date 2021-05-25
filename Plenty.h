#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class List;													// Дружественный класс
																// Указатель на элемент типа int
public:
	int* el;
	Iterator() { el = 0; }											// Конструктор без параметров
	Iterator(const Iterator& it) { el = it.el; }					// Конструктор копирования
	bool operator ==(const Iterator& it) { return (el == it.el); }	// Операция сравнения
	bool operator !=(const Iterator& it) { return (el != it.el); }	// Операция сравнения
	void operator ++() { ++el; }										// Инкремент
	void operator --() { --el; }										// Декремент 
	void operator -=(int N) { el -= N; }								// Переход на N элементов влево
	int& operator *() const { return *el; }							// Разыменовывание
};

class Plenty
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Plenty(int s, int k = 0);
	//конструктор с параметрами
	 Plenty(const Plenty&a);
	//деструктор
	~Plenty();
	//оператор присваивания 
	Plenty&operator=(const Plenty&a);
	//операция доступа по индексу 
	int&operator[](int index);
	//операция для добавление константы 
	Plenty operator+(const int k);
	//операция, возвращающая длину вектора 
	int operator()();
	//перегруженные операции ввода-вывода
friend ostream& operator<<(ostream& out, const Plenty& a); 
friend istream& operator>>(istream& in, Plenty& a); 
Iterator first(){
	return beg; 
}//возвращает указатель на первый элемент
Iterator last(){
	return end;
}//возвращает указатель на элемент следующий запоследним 
private:
	int size; 
	int len;
	int* data;
	Iterator beg;//указатель на первый элемент вектора 
	Iterator end;//указатель на элемент следующий за последним
};
