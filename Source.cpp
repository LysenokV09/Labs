#include <iostream>
using namespace std;

class Count
{
public:
	string st,cc;
	int peop;
	double S;

	Count(string proctype, string cctype, int OPsize, int JDsize)
	{
		cc = cctype;
		st = proctype;
		peop = OPsize;
		S = JDsize;
	};

	void Print()
	{
		cout <<"������: " <<cc<< "\n�������: " << st << "\n��������� (���): " << peop << "\n������� (���. �� ��): " << S;
	}
};

int main()
{
	system("chcp 1251>nul");
	string st, cc;
	int peop;
	double S;
	cout << "����� �������� ������. �������, ���������� ���������, �������" << endl;
	cin >>cc>> st >> peop >> S;
	Count a( cc, st, peop, S);
	a.Print();
}
