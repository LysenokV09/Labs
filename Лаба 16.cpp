#include <iostream>
#include <fstream>
using namespace std;

void estestv_sl(int* arr, int r, int t)
{
    int p = 1;
    int k = 1;
    int i = 0;
    bool f = false;
    while (arr[i] <= arr[i + 1] && i < r - 1)
    {
        p++;
        i++;
    }
    if (arr[i] > arr[i + 1] && i < r - 1)
    {
        i++;
        f = true;
        while (arr[i] <= arr[i + 1] && i < r - 1)
        {
            k++;
            i++;
        }
    }
    int num = i + 1;
    int* a = new int[p];
    int* b = new int[k];
    for (i = 0; i < p; i++)
    {
        a[i] = arr[i];
    }
    int g = 0;
    if (f)
    {
        for (i = p; i < p + k; i++)
        {
            b[g] = arr[i];
            g++;
        }
    }
    int j = 0;
    int l = 0;
    if (f)
    {
        for (i = 0; i < num; i++)
        {
            if ((a[l] < b[j] || j >= k) && l < p)
            {
                arr[i] = a[l];
                l++;
            }
            else

                if ((a[l] > b[j] || l >= p) && j < k)
                {
                    arr[i] = b[j];
                    j++;
                }
                else
                    if (a[l] == b[j] && j < k && l < p)
                    {
                        arr[i] = a[l];
                        arr[i + 1] = b[j];
                        l++;
                        j++;
                        i++;
                    }
        }
    }
    delete[] a;
    delete[] b;
}
void estestv_sort(int* arr, int r, int i)
{
    if (i < r)
    {
        estestv_sl(arr, r, i);
        estestv_sort(arr, r, i + 1);
    }
}
void balance_sort(int* arr, int first, int last)
{
    int middle, start, final, j;
    int* array = new int[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
    {
        if ((start <= middle) && ((final > last) || (arr[start] < arr[final])))
        {
            array[j] = arr[start];
            start++;
        }
        else
        {
            array[j] = arr[final];
            final++;
        }
    }
    for (j = first; j <= last; j++)
    {
        arr[j] = array[j];
    }
    delete[]array;
}

void balance_sl(int* arr, int r, int i)
{
    if (r < i)
    {
        balance_sl(arr, r, (r + i) / 2);
        balance_sl(arr, (r + i) / 2 + 1, i);
        balance_sort(arr, r, i);
    }
}

void mnogofaz_sl(int* arr)
{
    int a1[13], a2[13], a3[13], a4[13], a5[13], a6[13], a7[13], a8[13], a9[13], a10[13], a11[13], a12[13], a13[13];
    a1[0] = arr[0];
    a2[0] = arr[1];
    a3[0] = arr[2];
    a4[0] = arr[3];
    a5[0] = arr[4];
    a6[0] = arr[5];
    a7[0] = arr[6];
    a8[0] = arr[7];
    a9[0] = arr[8];
    a10[0] = arr[9];
    a11[0] = arr[10];
    a12[0] = arr[11];
    a13[0] = arr[12];

    //___5___8___0___

    a1[1] = a6[0]; estestv_sort(a1, 1, 0);
    a2[1] = a7[0]; estestv_sort(a2, 1, 0);
    a3[1] = a8[0]; estestv_sort(a3, 1, 0);
    a4[1] = a9[0]; estestv_sort(a4, 1, 0);
    a5[1] = a10[0]; estestv_sort(a5, 1, 0);

    //___0___3___5___

    a1[2] = a11[0]; estestv_sort(a1, 2, 0);
    a2[2] = a12[0]; estestv_sort(a2, 2, 0);
    a3[2] = a13[0]; estestv_sort(a3, 2, 0);

    //___3___0___2___

    a2[3] = a4[0];
    a2[4] = a4[1]; estestv_sort(a2, 4, 0);
    a3[3] = a5[0];
    a3[4] = a5[1]; estestv_sort(a3, 4, 0);

    //___1___2___0___

    a2[5] = a1[0];
    a2[6] = a1[1];
    a2[7] = a1[2]; estestv_sort(a2, 7, 0);

    //___0___1___1

    a2[8] = a3[0];
    a2[9] = a3[1];
    a2[10] = a3[2];
    a2[11] = a3[3];
    a2[12] = a3[4]; estestv_sort(a2, 13, 0);

    //___1___0___0

    for (int i = 0; i <= 12; i++)
    {
        arr[i] = a2[i];
    }
}

void show_struct(int* t, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " " << endl;
    }
}
int main()
{
    system("chcp 1251>nul");
    ifstream input("input.txt");
    ofstream output("output.txt");
    int data[20];
    cout << "Введите количество элементов: ";
    int n;
    cin >> n;
    while (n <= 0 || n > 20) {
        cout << "Вы ввели некорректное значение\n";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        input >> data[i];
    }
    bool f = true;
    int menu;
    while (f)
    {
        cout << endl << "Меню" << endl;
        cout << "1. Показать список." << endl << endl;
        cout << "2. Сортировка методом естественного слияния." << endl << endl;
        cout << "3. Сортировка методом сбалансированного слияния." << endl << endl;
        cout << "4. Сортировка многофазным слиянием." << endl << endl;
        cout << "5. Сброс всех сортировок." << endl << endl;
        cout << "6. Завершение работы." << endl << endl;
        cout << "Ввод: ";
        cin >> menu;
        switch (menu){
        case 1:{
            cout << endl << "Ваша структура:" << endl << endl;
            show_struct(data, n);
            cout << endl;
        }
        break;
        case 2:{
            cout << endl << "Сортировка методом естественного слияния: " << endl << endl;
            estestv_sort(data, n, 0);
            show_struct(data, n);
        }
        break;
        case 3:{
            cout << endl << "Сортировка методом сбалансированого слияния: " << endl << endl;
            balance_sl(data, 0, n - 1);
            show_struct(data, n);
        }
        break;
        case 4:{
            cout << endl << "Сортировка многофазным слиянием: " << endl << endl;
            mnogofaz_sl(data);
            show_struct(data, n);
        }
        break;
        case 5:{
            cout << endl << "Откат..." << endl << endl;
            input.seekg(0, ios_base::beg);
            for (int i = 0; i < n; i++) {
                input >> data[i];
            }
            show_struct(data, n);
        }
        break;
        case 6:
            cout << endl << "До свидания!" << endl << endl;
            f = false;
            break;
        default:
            cout << "Ввод неверный!" << endl << endl;
            break;
        }
    }
}

