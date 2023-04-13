#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> naturalDivisors(int k);
void stringMultiplicity(string str);
int IsKPeriodic(string str, int k);
void outArr(vector<int> arr);

// Вычисление натуральных делителей числа k
vector<int> naturalDivisors(int k) {
    vector<int> arr;
    int i = 1;

    while (count(arr.begin(), arr.end(), i) == 0) {
        if (k % i == 0) {
            arr.push_back(i);
            arr.push_back(k / i);   
        }
        ++i;
    }
    return arr;
}


// Вычисление всех возмохных кратностей строки на основе вычисление натуральных делителей длины строки, и проверкой вхождения на кратность подстрок длиной в делитель
void stringMultiplicity(string str)
{
    int k;
    vector<int> arr = naturalDivisors(str.size());

    cout << "Строка - " + str << " имеет кратность: " << endl;
    for (int i = 0; i < arr.size(); ++i) {
        k = IsKPeriodic(str, arr[i]);
        if (k > 0) {
            cout << '\t' << arr[i] << ", так как состоит из подстрки - " << str.substr(0, arr[i]) << endl;
        }
        else {
            arr.erase(arr.begin() + i);
            --i;
        }
    }
    cout << endl;
}

// Вычисление кратности строки на осное проверки кратности длины строки числу k, и вхождение подстроки от 0 до k в основную строку последовательно и кратно
int IsKPeriodic(string str, int k) {
    if (k < 1 || k > str.size()) {
        cout << "Некорректные данные \n";
        return -1;
    }
    
    int col = 0;

    if (str.size() % k == 0) {
        string sub_str = str.substr(0, k), tmp_str;

        for (int i = 0; i < str.size(); i += k) {
            tmp_str = str.substr(i, k);
            if (sub_str == tmp_str) {
                ++col;
            }
            else {
                return -1;
            }
        }
    }
    else {
        return -1;
    }

    return col;
}

void outArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{   
    setlocale(LC_ALL, "rus");

    string str_1 = "abcabcabcabcabcabc";
    string str_2 = "ABABCABABABABCABAB";
    string str_3 = "ABABCABAB";

    stringMultiplicity(str_1);
    stringMultiplicity(str_2);
    stringMultiplicity(str_3);

    int k = IsKPeriodic(str_1, 3);
    if(k > 0)
        cout << "Строка - " + str_1 << " имеет кратность: " << str_1.size() / k << ", так как состоит из подстрки - " << str_1.substr(0, str_1.size() / k) << endl;

    k = IsKPeriodic(str_1, 9);
    if (k > 0)
        cout << "Строка - " + str_1 << " имеет кратность: " << str_1.size() / k << ", так как состоит из подстрки - " << str_1.substr(0, str_1.size() / k) << endl;

    k = IsKPeriodic(str_2, 9);
    if (k > 0)
        cout << "Строка - " + str_2 << " имеет кратность: " << str_2.size() / k << ", так как состоит из подстрки - " << str_2.substr(0, str_1.size() / k) << endl;
}