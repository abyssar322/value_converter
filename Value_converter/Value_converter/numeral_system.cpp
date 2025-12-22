#include <iostream>
#include "numeral_system.h"

void num_syst()
{
	using namespace std;

	const int size = 100;
	bool error = false, repeat = true;
	int k, num_syst = 0, start_value;
	char res_str[size], start_str[size];

	while (repeat)
	{
		error = false;
		int sum = 0;

		cout << "\nИз какой СИ вы хотите перевести число: \n";
		cout << "1 - Шестнадцатеричная \n";
		cout << "2 - Десятичная \n";
		cout << "3 - Восьмеричная \n";
		cout << "4 - Двоичная \n";

		cout << "5 - Выйти из функции\n\n";
		
		cin >> k;
		cin.clear();
		cin.ignore();

		switch (k)
		{
		case 1:
		{
			num_syst = 16;

			cout << "Введите положительное число, которое вы хотите преобразовать: "; cin >> start_str;

			int frst_non_zero = search_first_non_zero(start_str);

			for (int i = frst_non_zero; i < strlen(start_str); i++)
			{
				if (('A' <= start_str[i] && start_str[i] <= 'F') ||
					('a' <= start_str[i] && start_str[i] <= 'f') ||
					('0' <= start_str[i] && start_str[i] <= '9'))
				{
					toDec(start_str, &sum, num_syst, i);
				}
				else
				{
					cout << "Вы ввели неправильное число в данной СИ \n";
					error = true;
					break;
				}
			}
			break;
		}

		case 2:
		{
			num_syst = 10;

			cout << "Введите положительное число, которое вы хотите преобразовать: "; cin >> start_str;

			int frst_non_zero = search_first_non_zero(start_str);

			for (int i = frst_non_zero; i < strlen(start_str); i++)
			{
				if ('0' <= start_str[i] && start_str[i] <= '9')
				{
					toDec(start_str, &sum, num_syst, i);
				}
				else
				{
					cout << "Вы ввели неправильное число в данной СИ \n";
					error = true;
					break;
				}
			}
			break;
		}

		case 3:
		{
			num_syst = 8;

			cout << "Введите положительное число, которое вы хотите преобразовать : "; cin >> start_str;

			int frst_non_zero = search_first_non_zero(start_str);

			for (int i = frst_non_zero; i < strlen(start_str); i++)
			{
				if ('0' <= start_str[i] && start_str[i] <= '7')
				{
					toDec(start_str, &sum, num_syst, i);
				}
				else
				{
					cout << "Вы ввели неправильное число в данной СИ \n";
					error = true;
					break;
				}
			}
			break;
		}

		case 4:
		{
			num_syst = 2;

			cout << "Введите число, которое вы хотите преобразовать: "; cin >> start_str;

			int frst_non_zero = search_first_non_zero(start_str);

			for (int i = frst_non_zero; i < strlen(start_str); i++)
			{
				if ('0' <= start_str[i] && start_str[i] <= '1')
				{
					toDec(start_str, &sum, num_syst, i);
				}
				else
				{
					cout << "Вы ввели неправильное число в данной СИ \n";
					error = true;
					break;
				}
			}
			break;
		}
		case 5: { 
			repeat = false; 
			continue;
			break;
		}
		default: {
			cout << "Ошибка ввода\n";
			error = true;
			break;
		}
		}

		if (error == false)
		{
			cout << "В какую СИ вы хотите перевестись: \n";
			cout << "1 - Шестнадцатеричная \n";
			cout << "2 - Десятичная \n";
			cout << "3 - Восьмеричная \n";
			cout << "4 - Двоичная \n";
			cin >> k;
			switch (k)
			{
			case 1:
			{
				_itoa_s(sum, res_str, 16);
				break;
			}
			case 2: {
				_itoa_s(sum, res_str, 10);
				break;
			}
			case 3: {
				_itoa_s(sum, res_str, 8);
				break;
			}
			case 4: {
				_itoa_s(sum, res_str, 2);
				break;
			}
			default:
			{
				cout << "Ошибка ввода"; repeat = false; continue;
			}
			}

			cout << "Результат преобразования: \n";
			for (int i = 0; i < strlen(res_str); i++)
			{
				cout << res_str[i];
			}	
		}
		cout << "\n\n";
		cout << "Хотите ли вы ещё раз воспользоваться этой функцией\n1 - Да \n2 - Нет\n"; cin >> k;
		switch (k)
		{
		case 1: break;
		case 2: repeat = false; break;
		default:
		{
			cout << "Ошибка ввода"; repeat = false; break;
		}
		}
		
	}

}