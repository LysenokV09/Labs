#include <iostream>
using namespace std;
class Func
{
public:
	double x, first, second,y;

	double root(double first, double second, double y)
	{
		if (first == 0) 
		{
			return -1;
		}
		return (y - second) / first;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Func Urav;
	cout << "Поиск корня функции y=Ax+B, при различных значениях A, B, x" << endl;
	cout << "Введи y" << endl;
	cin >> Urav.y;
	cout << "Введи A" << endl;
	cin >> Urav.first;
	cout << "Введи B" << endl;
	cin >> Urav.second;
	if (Urav.root(Urav.first, Urav.second, Urav.y) == -1){
		cout << "Уравнения не существует.";
	}
	else {
		cout << "Ответ: Корень уравния =  " << Urav.root(Urav.first, Urav.second, Urav.y);
	}
}
