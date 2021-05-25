#include <iostream>
#include <stdio.h>
#include <string>
#include<fstream>
using namespace std;
struct Peop {
    string fio;
    string ad;
    int np;
};
int* a;
void INFILE(Peop b[], const int size)
{
    ifstream file("MyFile.txt");
    if (file) {
        for (int i = 0; i < size; i++) 
        {
            getline(file, b[i].fio);
            getline(file, b[i].ad);
            file>> b[i].np;
            file.ignore();
        }
    }
}
void Vvod(Peop b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << "������� ��� ��������:" << endl;
        getline(cin, b[i].fio);
        cout << "������� ������:" << endl;
        getline( cin, b[i].ad);
        cout << "������� ����� ��������" << endl;
        cin >> b[i].np;
        cin.ignore();
    }
};
void vivod(Peop b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "��� : " << b[i].fio << endl;
        cout << "������: " << b[i].ad << endl;
        cout << "����� ��������: " << b[i].np << endl;
    }
};
int search(Peop b[], string substr, const int size) {
    int strl, substrl, res = -1;
    substrl = substr.size();
    for (int i = 0; i < size; i++) {
        string str = b[i].ad;
        strl = b[i].ad.size();
        if (strl != 0 && substrl != 0) {
            for (int j = 0; j < substrl; j++) {
                if (substr[j] != str[j]) {
                    break;
                }
                else if (j == substrl - 1) {
                    res = i;
                    break;
                }
            }
        }
    }
    if (res == -1) {
        cout << "������ �������� ���" << endl;
    }
    else {
        cout << "���: " << b[res].fio << endl;
        cout << "������: " << b[res].ad << endl;
        cout << "����� ��������: " << b[res].np << endl;
    }
    return 0;
}
int InterpolSearch(Peop b[], int* a, int size, int key) {
    int mid, left = 0, right = size - 1;
    int c = -2;
    for (int y = 0; y < size; y++) {
        a[y] = b[y].np;
    }
    bool f = true;
    while (f == true)
    {
        f = false;
        for (int re = size - 1; re >= 1; re--)
        {
            if (a[re - 1] > a[re])
            {
                int  o = a[re];
                a[re] = a[re - 1];
                a[re - 1] = o;
                f = true;
            }
        }
    }
    while (a[left] <= key && a[right] >= key) {
        mid = left + ((key - a[left]) * (right - left)) / (a[right] - a[left]);
        if (a[mid] < key)  left = mid + 1;
        else   if (a[mid] > key)  right = mid - 1;
        else return mid;
    }
    if (a[left] == key)return left;
    else return -1;
}
void LineSearch(Peop b[], int size) {
     int key2;
        cout <<endl<< "������� ����� �������� ��������, �������� �� �����(�������� �����):  ";
        cin >> key2;
    for (int i = 0; i < size; i++) {
        if (b[i].np == key2) {  
            cout << "��� : " << b[i].fio << endl;
            cout << "������ " << b[i].ad << endl;
            cout << "����� �������� " << b[i].np << endl;
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int* a;
    int size = 0, m, key;
    string substr;
    while (size <= 0||size>7)
    {
        cout << "������� ���������� �������, �� ������ 7:" << endl;
        cin >> size;
    }
    a = (int*)malloc((size) * sizeof(int));//��������� ������ ��� ������
    Peop* b = new Peop[size];
    cout << "Deustv" << endl;
    cout << "1. ������ �� �����" << endl;
    cout << "2. ���������� ������� " << endl;
    cin >> m;
    while (m != 1 && m != 2)
    {
        cin >> m;
    }
    if (m == 1)
    {
        INFILE(b, size);
    }
    else
    {
        cin.ignore();
       Vvod(b, size);
    }
       vivod(b, size);
       LineSearch(b, size);
       cout <<endl<< "������� ����� ��������, �������� �� �����" << endl;
       cin>>substr;
       search(b, substr, size);
            cout << "������� ����� �������� ��������, �������� �� �����(���������������� �����):" << endl;
            cin >> key;
       
        cin.ignore();
        
      if (InterpolSearch(b, a, size, key) == -1)
        {
            cout << "������� �� ������" << endl;
        }
        else {
            for (int i = 0; i < size; i++)
            {
                if (b[i].np == a[InterpolSearch(b, a, size, key)])
                {
                    cout << "���: " << b[i].fio << endl;
                    cout << " ������: " << b[i].ad << endl;
                    cout << "����� ��������: " << b[i].np << endl;
                }
            }
        }
        
    return 0;
}