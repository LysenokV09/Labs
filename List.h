#pragma once
#include "Object.h"

class List
{
protected:
	Object** Beg;
	int Size;													
	int Cur;
public:
	List();
	List(int N);
	~List();
	void Add();
	void Del();
	void Show();
	void Elem(int Index);
	int operator() ();
};

