#include <iostream>

#include "money_conv.h"

void money_conv()
{
	using namespace std;

	int k;
	bool repeat = true;
	
	

	const double usd = 1.0;
	const double eur = 0.8546;
	const double byn = 2.9343;
	const double rub = 78.8727;
	const double jpy = 155.903;
	const double cad = 1.3811;
	const double gpb = 0.748;
	

	while (repeat)
	{
		double to_usd, result = 0;
		double money;
		bool error = false;

		cout << "\nИз какой валюты вы хотите перевестись: \n";
		cout << "1 - Белорусский рубль BYN \n";
		cout << "2 - Российский рубль RUB \n";
		cout << "3 - Доллар США USD \n";
		cout << "4 - Евро EUR \n";
		cout << "5 - Фунт стерлингов GBP \n";
		cout << "6 - Японская иена JPY \n";
		cout << "7 - Канадский доллар CAD \n\n";

		cout << "8 - Информация о курсе доллара USD \n\n";
		
		cout << "9 - Выйти из функции\n\n";
		cin >> k;
		cin.clear();
		cin.ignore();

		switch (k)
		{
		case 1:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(byn, money);
			break;
		}

		case 2:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(rub, money);
			break;
		}

		case 3:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(usd, money);
			break;
		}

		case 4:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(eur, money);
			break;
		}

		case 5:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(gpb, money);
			break;
		}

		case 6:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(jpy, money);
			break;
		}

		case 7:
		{
			cout << "Введите величину: "; cin >> money;
			to_usd = to_the_usd(cad, money);
			break;
		}
		case 8:
		{
			cout << "\nUSD = " << usd << " USD" << endl;
			cout << "EUR = " << eur << " USD" << endl;
			cout << "BYN = " << byn << " USD" << endl;
			cout << "RUB = " << rub << " USD" << endl;
			cout << "GBP = " << gpb << " USD" << endl;
			cout << "JPY = " << jpy << " USD" << endl;
			cout << "CAD = " << cad << " USD" << endl;
			continue;
		}

		case 9: {
			repeat = false;
			continue;
			break;
		}

		default:
			cout << "\nОшибка ввода\n\n"; error = true; break;
			break;
		}

		if (error == false)
		{
		
		cout << "\nВ какую валюту вы хотите перевестись: \n";
		cout << "1 - Белорусский рубль BYN \n";
		cout << "2 - Российский рубль RUB \n";
		cout << "3 - Доллар США USD \n";
		cout << "4 - Евро EUR \n";
		cout << "5 - Фунт стерлингов GBP \n";
		cout << "6 - Японская иена JPY \n";
		cout << "7 - Канадский доллар CAD \n\n";
		cin >> k;
		switch (k)
		{
		case 1:
		{
			result = serch_res(to_usd, byn);
			break;
		}

		case 2:
		{
			result = serch_res(to_usd, rub);
			break;
		}

		case 3:
		{
			result = serch_res(to_usd, usd);
			break;
		}

		case 4:
		{
			result = serch_res(to_usd, eur);
			break;
		}

		case 5:
		{
			result = serch_res(to_usd, gpb);
			break;
		}

		case 6:
		{
			result = serch_res(to_usd, jpy);
			break;
		}

		case 7:
		{
			result = serch_res(to_usd, cad);
			break;
		}
		default:
		{
			cout << "\nОшибка ввода"; repeat = false; continue;
		}
		}
		cout << "\nРезультат вычисления равен: " << result;

		cout << "\n\n";
		}


		cout << "Хотите ли вы ещё раз воспользоваться этой функцией\n1 - Да \n2 - Нет  \n\n"; cin >> k;
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