#pragma once
#include "car.h" 
class Lorry :
	public Car
{
public:
	Lorry(void);
public:
	void Show();
	~Lorry(void);
	Lorry(int, int, double);
	Lorry(const Lorry&);
	int Get_gipot() {
		return gipot;
	}
	void Set_Gipot(double);
	Lorry& operator=(const Lorry&);
	friend istream& operator>>(istream& in, Lorry& l);
	friend ostream& operator<<(ostream& out, const Lorry& l);
	double gipot;
};
