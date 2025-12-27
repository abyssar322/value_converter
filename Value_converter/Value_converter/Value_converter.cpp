#include <iostream>
#include "header.h"

int main()
{
	
	setlocale(LC_ALL, "rus");

	using namespace std;

	int choose;
	bool repeat = true;

	while (repeat)
	{

		cout << "\n--- КОНВЕРТЕР ВЕЛИЧИН ---\n";
	cout << "К какой функции вы хотите обратиться: \n"; 
	cout << "1 - Валюты" << endl;
	cout << "2 - Длина" << endl;
	cout << "3 - Площадь" << endl;
	cout << "4 - Объём" << endl;
	cout << "5 - Масса" << endl;
	cout << "6 - Температура" << endl;
	cout << "7 - Скорость" << endl;
	cout << "8 - Давление" << endl;
	cout << "9 - Мощность" << endl;
	cout << "10 - Системы счисления" << endl << endl;

	cout << "11 - Выход из программы" << endl << endl;

	cin >> choose;
		cin.clear();
		cin.ignore();

	switch (choose)
	{
	case 1: 
	{
		money_conv();
		break;
	}

	case 2:
	{
		length_conv();
		break;
	}

	case 3:
	{
		Area_conv();
		break;
	}

	case 4:
	{
		volcalculation();
		break;
	}

	case 5:
	{
		Weight_conv();
		break;
	}

	case 6:
	{
		tempcalculation();
		break;
	}

	case 7:
	{
		Speed_conv();
		break;
	}

	case 8:
	{
		pressure_conv();
		break;
	}

	case 9:
	{
		Power_conv();
		break;
	}

	case 10:
	{
		num_syst();
		break;
	}

	case 11: {
		repeat = false;

		continue;
		break;
	}

	default:
	{
		cout << "Ошибка ввода:";
		break;
	}
	

	}
	cout << "\n\n";
	cout << "Хотите ли вы ещё раз воспользоваться программой\n1 - Да \n2 - Нет\n\n"; cin >> choose;  cin.clear(); cin.ignore();
	switch (choose)
	{
	case 1: break;

	case 2: repeat = false; break;

	default: 
	{
		cout << "\nОшибка ввода\n\n";
		break;
	}
	}

	}

	system("pause");

	return 0;
}