#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class People : public Object
{
protected:
	string Name;
	int Age;
public:
	People();
	People(string name, int age);
	People(const People& Ptr);
	virtual ~People();
	void Show();
	void Input();
	string Get_Name() { return Name; }
	int Get_Age() { return Age; }
	void Set_Name(string name) { Name = name; }
	void Set_Age(int age) { Age = age; }
	People& operator =(const People& Ptr);
};