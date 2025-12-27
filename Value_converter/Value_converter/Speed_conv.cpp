#include <iostream>

// Вспомогательные функции (аналоги ваших to_the_usd и serch_res)
double to_base_speed(double rate, double value) { return value / rate; }
double from_base_speed(double base_val, double rate) { return base_val * rate; }

void Speed_conv() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    int k;
    bool repeat = true;

    // Коэффициенты (сколько единиц в 1 метре в секунду)
    const double mps = 1.0;       // Метры в секунду
    const double kmh = 3.6;       // Километры в час
    const double knots = 1.94384; // Узлы
    const double mach = 0.002938; // Число Маха (при 20°C)

    while (repeat) {
        double base_val, result = 0, value;
        bool error = false;

        cout << "\n--- КОНВЕРТЕР СКОРОСТИ ---\n";
        cout << "\nВыберите исходную единицу скорости:\n";
        cout << "1 - Метры в секунду (м/с)\n2 - Километры в час (км/ч)\n";
        cout << "3 - Узлы (kn)\n";
        cout << "4 - Число Маха (M)\n\n";
        cout << "5 - Выйти из функции\n";
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

        // Переводим в базовую единицу (м/с)
        switch (k) {
        case 1: base_val = to_base_speed(mps, value); break;
        case 2: base_val = to_base_speed(kmh, value); break;
        case 3: base_val = to_base_speed(knots, value); break;
        case 4: base_val = to_base_speed(mach, value); break;
        default: cout << "Ошибка ввода"; break;
        }

        cout << "\nВ какую единицу перевести:\n";
        cout << "1 - Метры в секунду\n2 - Километры в час\n3 - Узлы\n4 - Махи\n";
        cin >> k;
        cin.clear(); cin.ignore();

        switch (k) {
        case 1: result = from_base_speed(base_val, mps); break;
        case 2: result = from_base_speed(base_val, kmh); break;
        case 3: result = from_base_speed(base_val, knots); break;
        case 4: result = from_base_speed(base_val, mach); break;
        default: { cout << "Ошибка выбора\n"; error = true; break; }
        }

        if (!error) cout << "Результат: " << result << endl;

        cout << "\nЕще раз? 1 - Да, 2 - Нет: "; cin >> k;
        if (k != 1) repeat = false;
    }
}
