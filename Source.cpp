#include <iostream>
#include <list>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>
using namespace std;
struct Peop
{
    string fio;
    string bday;
    string ph;
    string np;
};
int Hash_task(string s, int n)
{
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x += (int)(s[i]) * (i + 1);
    }
    return (int)(n * (0.3 * x - (int)(0.3 * x)));
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int len = -1;
    int adress;
    Peop x;
    string droh;
    int error = 0;
    while (len < 2 || len>100)
    {
        cout << "Введите размер таблицы\n";
        cin >> len;
    }
    const int N = len;
    cin.get();
    Peop* data_base = new Peop[len];
    string* key = new string[len];
    for (int i = 0; i < len; i++) key[i] = "404";
    ifstream F1("Data.txt");
    for (int i = 0; i < N; i++)
    {
        getline(F1, x.fio);
        getline(F1, x.bday);
        getline(F1, x.ph);
        getline(F1, x.np);
        adress = Hash_task(x.bday, N);
        while (adress >= len || key[len - 1] != "404")
        {
            Peop* data_base_new = new Peop[len * 2];
            string* key_new = new string[len * 2];
            for (int i = 0; i < len; i++)
            {
                data_base_new[i] = data_base[i];
                key_new[i] = key[i];
            }
            for (int i = len; i < len * 2; i++) key_new[i] = "404";
            delete[] data_base;
            delete[] key;
            data_base = data_base_new;
            key = key_new;
            len *= 2;
        }
        if (key[adress] != "404")
        {
            error++;
            while (key[adress] != "404") adress++;

        }
        data_base[adress] = x;
        key[adress] = x.bday;
        cout << "Вывод объектов\n";
        cout << "ФИО            - " << data_base[adress].fio << endl;
        cout << "Дата рождения  - " << data_base[adress].bday << endl;
        cout << "Номер телефона - " << data_base[adress].ph << endl;
        cout << "Номер паспорта - " << data_base[adress].np << endl;
    }
   /* cout << "Таблица создана. Коллизий: " << error << endl;*/
    /*while (true)
    {*/
        cout << "Введите Дату рождения\n";
        cin >> droh;
       adress = Hash_task(droh, N);
        while (adress < len)
        {
            if (key[adress] == droh)
            {
                cout << "Объект найден:\n";
                cout << "ФИО            - " << data_base[adress].fio << endl;
                cout << "Дата рождения  - " << data_base[adress].bday << endl;
                cout << "Номер телефона - " << data_base[adress].ph << endl;
                cout << "Номер паспорта - " << data_base[adress].np << endl;
                break;
            }
            if (key[adress] == "404")
            {
                cout << "Неизвестный объект [404]\n";
                break;
            }
            adress++;
        }
        if (adress == len)
        {
            cout << "Неизвестный объект [404]\n";
        }
    /*}*/
}