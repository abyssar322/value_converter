#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "volume.h"

using namespace std;

static bool is_float(const string& str) {  //Проверка на float число
    if (str.empty()) return false;
    istringstream ss(str);
    double val;
    return (ss >> val) && (ss.eof());
}

int volcalculation()
{
    int original, needful;
    float value, result;
    string input;

    setlocale(LC_ALL, "Russian");

    cout << "Введите исходную единицу измерения (1 - Миллилитры ml, 2 - литры l , 3 - Кубические сантиметры cm^3, 4 - Американские галлоны gal)" << endl;
    cin >> original;
    if (original != 1 && original != 2 && original != 3 && original !=4) {
        cout << "Неверный ввод исходной единицы измерения" << endl;
        return 0;
    }

    cout << "Введите нужную единицу измерения (1 - Миллилитры ml, 2 - литры l , 3 - Кубические сантиметры cm^3, 4 - Американские галлоны gal)" << endl;
    cin >> needful;
    if (needful != 1 && needful != 2 && needful != 3 && needful != 4) {
        cout << "Неверный ввод нужной единицы измерения" << endl;
        return 0;
    }

    cout << "Введите величину" << endl;
    cin >> input;
    if (!is_float(input)) { //Проверка на float число
        cout << "Неверный ввод величины, ожидалось число." << endl;
        return 0;
    }
    value = stof(input);


    switch (original) {
    case 1: {
        switch (needful) {
        case 1:
            result = value;
            break;
        case 2:
            result = value / 1000;
            break;
        case 3:
            result = value;
            break;
        case 4:
            result = value / 3785.41;
            break;
        default:
            break;
        }
        break;
    }
    case 2: {
        switch (needful) {
        case 1:
            result = value / 1000;
            break;
        case 2:
            result = value;
            break;
        case 3:
            result = value * 1000;
            break;
        case 4:
            result = value / 3.78541;
            break;
        default:
            break;
        }
        break;
    }

    case 3: {
        switch (needful) {
        case 1:
            result = value;
            break;
        case 2:
            result = value / 1000;
            break;
        case 3:
            result = value;
            break;
        case 4:
            result = value / 3785.41;
            break;
        default:
            break;
        }
        break;
    }

    case 4: {
        switch (needful) {
        case 1:
            result = value * 3785.41;
            break;
        case 2:
            result = value * 3.78541;
            break;
        case 3:
            result = value * 3785.41;
            break;
        case 4:
            result = value;
            break;
        default:
            break;
        }
        break;
    }
    default: {
        break;
    }
    }

    if (needful == 1) {
        cout << "Величина в нужной единице измерения : " << setprecision(3) << result << " ml " << endl;
    }
    else if (needful == 2) {
        cout << "Величина в нужной единице измерения : " << setprecision(3) << result << " l " << endl;
    }
    else if (needful == 3) {
        cout << "Величина в нужной единице измерения : " << setprecision(3) << result << " cm^3 " << endl;
    }
    else if (needful == 4) {
        cout << "Величина в нужной единице измерения : " << setprecision(3)<< result << " gal " << endl;
    }
    return 0;
}