#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
void hoar_sort(int* arr, int left, int right, string* name)
{
    system("chcp 1251>nul");
    int i = left, j = right, pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while ((arr[i] < pivot) && (i < right))i++;
        while ((pivot < arr[j]) && (j > left))j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            swap(name[i], name[j]);
            i++; j--;
        }
    }
    if (left < j)hoar_sort(arr, left, j, name);
    if (i < right)hoar_sort(arr, i, right, name);
}
void shell_Sort(int* arr, int size, string* name)
{
    system("chcp 1251>nul");
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            string s = name[i];
            int j;
            for (j = i; j >= gap; j -= gap)
            {
                if (temp < arr[j - gap]) {
                    arr[j] = arr[j - gap];
                    name[j] = name[j - gap];
                }
                else
                    break;
            }
            arr[j] = temp;
            name[i] = s;
        }
    }
}
void print(int* arr, int size, string* name)
{
    system("chcp 1251>nul");
    for (int i = 0; i < size; i++)
    {
        cout << "ФИО : " << name[i] << " рост " << arr[i] << "  " << endl;
    }
}
int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "RUS");
    int size = 0;
    cout << "Введите количество человек : "; cin >> size;
    while (size <= 0) {
        cout << "введите правильное количество человек";
        cin >> size;
    }
    int* arr = new int[size];
    string* name = new string[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Введите ФИО" << endl;
        cin.ignore();
        getline(cin, name[i]);
        cout << "Введите рост ";
        cout << endl;
        cin >> arr[i];
        while (arr[i] <= 0) {
            cout << "введите корректное значение роста ";
            cin >> arr[i];
        }
    }
    cout << "Люди которых Вы ввели" << endl;
    print(arr, size, name);
    hoar_sort(arr, 0, size - 1, name);
    cout << "  Сортировка Хоара " << endl;
    print(arr, size, name);
    shell_Sort(arr, size, name);
    cout << "  Сортировка  Шелла " << endl;
    print(arr, size, name);
    system("pause");
    return 0;
}