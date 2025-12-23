#include <iostream>
#include <locale>
#include "weight.h"
using namespace std;
void Weight_conv()
{
    using namespace std;

    int k;
    bool repeat = true;
    const double KG = 1.0;
    const double GRAM = 1000.0;
    const double TON = 0.001;
    const double POUND = 2.20462;

    while (repeat)
    {
        double to_standard = 0, result = 0;
        double weight;
        bool error = false;

        cout << "\n--- КОНВЕРТЕР МАССЫ ---\n";
        cout << "1 - Килограммы (кг),2 - Граммы (г),3 - Тонны (т),4 - Фунты (lb)\n";
        cout << "Выберите исходную единицу: \n";
        cin >> k;
        cout << "Введите значение массы: ";
        cin >> weight;
        if (weight <= 0)
        {
            cout << "Масса не должна быть отрицательной или равна 0";
            break;
        }

        switch (k)
        {
        case 1: to_standard = weight; break;
        case 2: to_standard = weight / GRAM; break;
        case 3: to_standard = weight / TON; break;
        case 4: to_standard = weight / POUND; break;
        default:  error = true; break;
        }

        if (!error)
        {
            cout << "\nВ какую перевести?(1 - Килограммы,2 - Граммы,3 - Тонны,4 - Фунты\n";
            cin >> k;
            cin.clear();
            cin.ignore();
            switch (k)
            {
            case 1: result = to_standard; break;
            case 2: result = to_standard * GRAM; break;
            case 3: result = to_standard * TON; break;
            case 4: result = to_standard * POUND; break;
            default: cout << "\nОшибка выбора\n"; error = true; break;
            }

            if (!error) {
                cout << "\nРезультат: " << result << endl;
            }
        }
        else
        {
            cout << "Ошибка при вводе выбора";
        }

        cout << "\nЕще раз? (1 - да, 2 - нет): ";
        cin >> k;
        if (k != 1) repeat = false;
    }
}
