#pragma once
#include "People.h"
using namespace std;

class Student : public People
{
protected:
	float Rating;
	string gr;
public:
	Student();
	Student(string name, int age, int rating);
	Student(const Student& Ptr);
	~Student();
	float Get_Rating() { return Rating; }
	void Set_Rating(float rating) { Rating = rating; }
	void Show();
	void Input();
	Student& operator =(const Student& Ptr);
};

