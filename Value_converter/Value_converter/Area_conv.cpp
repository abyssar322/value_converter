#include <iostream>

// Вспомогательные функции
double to_base_area(double rate, double value) { return value * rate; }
double from_base_area(double base_val, double rate) { return base_val / rate; }

void Area_conv() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    int k;
    bool repeat = true;

    // Коэффициенты (сколько кв. метров в данной единице)
    const double sq_meter = 1.0;
    const double hectare = 10000.0;
    const double acre = 4046.86;
    const double sq_km = 1000000.0;

    while (repeat) {
        double base_val, result = 0, value;
        bool error = false;
        cout << "\n--- КОНВЕРТЕР ПЛОЩАДИ ---\n";
        cout << "\nВыберите исходную единицу площади:\n";
        cout << "1 - Кв. метры\n2 - Гектары\n3 - Акры\n4 - Кв. километры\n\n5 - Выйти из функции\n";
        cin >> k;
        cin.clear();
        cin.ignore();

        if (k < 1 || k > 5) { cout << "Ошибка ввода\n"; break; }
        if (k == 5) {
            repeat = false;
            continue;
            break;
        }

        cout << "Введите значение: "; cin >> value;

        if (std::cin.fail()) {
            std::cout << "Ошибка! Пожалуйста, введите число (например: 100, 15.5, -20.3).\n";
            break;
        }

        if (value < 0) {
            value *= -1;
            cout << "Ваше число было меньше 0 поэтому мы сделали его положительным" << endl;
        }

        // Переводим в базовую единицу (кв. м)
        switch (k) {
        case 1: base_val = to_base_area(sq_meter, value); break;
        case 2: base_val = to_base_area(hectare, value); break;
        case 3: base_val = to_base_area(acre, value); break;
        case 4: base_val = to_base_area(sq_km, value); break;
        }

        cout << "\nВ какую единицу перевести:\n";
        cout << "1 - Кв. метры\n2 - Гектары\n3 - Акры\n4 - Кв. километры\n";
        cin >> k;
        cin.clear(); cin.ignore();

        switch (k) {
        case 1: result = from_base_area(base_val, sq_meter); break;
        case 2: result = from_base_area(base_val, hectare); break;
        case 3: result = from_base_area(base_val, acre); break;
        case 4: result = from_base_area(base_val, sq_km); break;
        default: { cout << "Ошибка выбора\n"; error = true; break; }
        }

        if (!error) cout << "Результат: " << result << endl;

        cout << "\nЕще раз? 1 - Да, 2 - Нет: "; cin >> k;
        if (k != 1) repeat = false;
    }
}
