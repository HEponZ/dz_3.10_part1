#include "String.h"

int main()
{
	setlocale(LC_ALL, "rus");
	String str1, str2;
	int choise = 0, index = 0;
	char symbol;
	enum MENU {
		EXIT = 0,
		SIN_STR,
		PRINT,
		COUNT_STRING,
		COUT_INDEX,
		FIND_SYMBOL
	};

	cout << "1 - Ввод новой строки\n2 - Вывод\n3 - Вывод кол-ва строк\n4 - Вывод символа по индексу из 1 строки\n0 - ВЫХОД\n";

	do
	{
		cin >> choise;

		switch (choise)
		{
		case SIN_STR:
			cin.ignore();
			cout << "Введите строку: ";
			cin >> str1;
			cout << "Введите вторую строку: ";
			cin >> str2;
			break;
		case PRINT:
			str1.print();
			str2.print();
			break;
		case COUNT_STRING:
			printf("Кол-во строк: %d\n", str1.get_count());
			break;
		case COUT_INDEX:
			cout << "Введите индекс: ";
			cin >> index;
			cout << str1[index] << "\n";
			break;
		case FIND_SYMBOL:
			cout << "Введите символ\n";
			cin >> symbol;
			cout << str2(symbol) << "\n";
			break;
		case EXIT:
			break;
		}

	} while (choise != 0);

	return 0;
}
