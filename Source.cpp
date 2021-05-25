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
        cout << "Введите ФИО: " << endl;
        getline(cin, b[i].fio);
        cout << "Введите адресс: " << endl;
        getline( cin, b[i].ad);
        cout << "Введите номер паспорта: " << endl;
        cin >> b[i].np;
        cin.ignore();
    }
};
void vivod(Peop b[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "ФИО : " << b[i].fio << endl;
        cout << "Адресс: " << b[i].ad << endl;
        cout << "Номер паспорта: " << b[i].np << endl;
    }
};
int BMF(string st, string ct)
{
    int stl, ctl;
    stl = st.size();
    ctl = ct.size();
    if (stl != 0 && ctl != 0 && stl >= ctl)
    {
        int i, p;
        int b[256];
        for (i = 0; i < 256; i++)
        {
            b[i] = ctl;
        }
        for (i = ctl - 2; i >= 0; i--)
        {
            if (b[int(unsigned char(ct[i]))] == ctl)
            {
                b[int(unsigned char(ct[i]))] = ctl - i - 1;
            }
        }
        p = ctl - 1;
        while (p < stl)
        {
            if (ct[ctl - 1] != st[p])
            {
                p += b[int((unsigned char)st[p])];
            }
            else
            {
                for (i = ctl - 1; i >= 0; i--)
                {
                    if (ct[i] != st[p - ctl + i + 1])
                    {
                        p += b[int((unsigned char)st[p])];
                        break;
                    }
                    else if (i == 0)
                    {
                        return p - ctl + 1;
                    }
                }
            }
        }
    }
    return -1;
}
int SPryanik(string str, string obr)
{
    {
        int pi[50];
        pi[0] = 0;


        int l;

        for (l = 1; obr[l]; ++l)
        {
            int j = pi[l - 1];
            while ((j > 0) && (obr[l] != obr[j]))
                j = pi[j - 1];
            if (obr[l] == obr[j])
                ++j;
            pi[l] = j;
        }
        int j = 0;

        for (int i = 0; str[i]; ++i)
        {
            while ((j > 0) && (str[i] != obr[j]))
                j = pi[j - 1];

            if (str[i] == obr[j])
                ++j;
            if (j == l)

                return 0;;
        }
        return -1;
    }
}
void SLine(Peop b[], int size) {
     int key2;
        cout <<endl<< "Введите номер паспорта человека, которого вы ищите(Линейный поиск):  ";
        cin >> key2;
    for (int i = 0; i < size; i++) {
        if (b[i].np == key2) {  
            cout << "ФИО : " << b[i].fio << endl;
            cout << "Адресс " << b[i].ad << endl;
            cout << "Номер паспорта " << b[i].np << endl;
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int* a;
    int size = 0, m, key;
    string substr, adres;
    while (size <= 0 || size > 7)
    {
        cout << "Введите количество человек, не больше 7:" << endl;
        cin >> size;
    }
    a = (int*)malloc((size) * sizeof(int));//Выделение памяти под массив
    Peop* b = new Peop[size];
    cout << "Выберите деальнейшее действие" << endl;
    cout << "1. Чтение из файла" << endl;
    cout << "2. Заполнение ручками " << endl;
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
    SLine(b, size);
    string keys;
    cout << "Введите ключ, фамилию студента: ";
    cin >> keys;
    int i = 0;
    bool y = true;
    while (y) {
        int r = SPryanik(b[i].fio, keys);
        if (r != -1) {
            cout << "Элемент найден!" << endl;
            cout << "ФИО:\t" << b[i].fio << endl;
            cout << "Адресс: \t" << b[i].ad << endl;
            cout << "Номер паспорта:\t" << b[i].np << endl;
            y = false;
        }
        else i++;
        if (i == size)
        {
            y = false;
        }
    }
    if (i == size) {
        cout << "Элемент не найден.";
    }

    cout << endl;
    cout << "Введите адрес человека, которого ищите: ";
    cin >> adres;
    for (int i = 0; i < size; i++) {

        if (BMF(b[i].ad, adres) != -1)
        {
            cout << "ФИО : " << b[i].fio << endl;
            cout << "Адресс " << b[i].ad << endl;
            cout << "Номер паспорта " << b[i].np << endl;
        }
    }

    return 0;
}