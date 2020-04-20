#include <iostream>
using namespace std;

enum init
{
	user_init = 1,
	random_init,
	default_init
};

//10. Напишите функцию, возвращающую ссылку на число, встречающееся в
//заданном массиве произвольного размера(аргумент функции) минимальное количество раз. 
//Если таких чисел несколько, то выбрать максимальное из них. Замените этот элемент значением k.

int& func(int* array, int size)
//функция, возвращающую ссылку на число, встречающееся в заданном массиве минимальное количество раз
{
	bool* flags = new bool[size] {};	//доп массив. 1 - число на соответствующей позиции позиции уже встречалось, 0 - нет
	unsigned int counter = 1,		 //счетчик для количества повторяющихся элементов
		min_counter = 1;			//и для хранения их минимального значения
	int number = array[0], min_index;			//число, встречающееся минимальное количество раз

	for (int temp, i = 0; i < size; counter = 1, i++)
	{
		if (flags[i] == 1) continue;
		else  flags[i] = 1;

		temp = array[i];
		for (int j = i + 1; j < size; j++)
		{
			if(flags[j] == 1) continue;
			if (array[j] == temp)
			{
				counter++;
				flags[j] = 1;
			}
		}

		if (i == 0) min_counter = counter;	//инициализируем минимальное количество первым полученным
											//не самый оптимальный вариант кода, но я не смогла придумать ничего лучше
		if (counter < min_counter)
		{
			min_counter = counter;
			min_index = i;
			number = temp;
		}
		else if (counter == min_counter && number < temp)
		{
			number = temp;
			min_index = i;
		}
	}
	return array[min_index];
}

int valid_input(int n)
{
	while (true)
	{
		cin >> n;
		if (cin) return n;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}
}

bool initialization(int* array, int size, int c)
//инициализация массива
{
	switch (c)
	{
	case user_init:
	{
		cout << "\nВведите элементы массива(int)\n";
		for (unsigned int i = 0; i < size; i++)
		{
			while (true)
			{
				cin >> array[i];
				if (cin) break;
				cin.clear();
				rewind(stdin);
				cout << "Неверное значение. Повторите ввод\t" << endl;
			}
		}
		break;
	}
	case random_init:
	{
		for (unsigned int i = 0; i < size; i++)
		{
			array[i] = rand() % 20 + 1;
			cout << array[i] << ' ';
		}
		break;
	}
	case default_init:
	{
		for (unsigned int i = 0; i < size; i++)
		{
			array[i] = i;
			cout << array[i] << ' ';
		}
		break;
	}
	default: cout << "\nwrong input\n"; return 0;
	}
	return 1;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int* array;
	unsigned int size;
	cout << "Введите размер массива:\t";
	size = valid_input(size = 0);
	array = new int[size];

	cout << "Выберите способ инициализации:\n"
		<< "1 - с клавиатуры\n"
		<< "2 - произвольными значениями\n"
		<< "3 - инициализация по умолчанию\n";

	unsigned int choice;
	cin >> choice;
	bool init  = initialization(array, size, choice);
	cout << endl;

	if (init)
	{
		int number = func(array, size);
		cout << "\nИскомое число:\t" << number << endl;

		int k;	 //значение на которое будут заменены подходящие элементы массива 
		cout << "Введите число для замены\t";
		k = valid_input(k = 0);
		func(array, size) = k;
		cout << "\nИзменненный массив:\n";
		for (int i = 0; i < size; i++)	cout << array[i] << ' ';
	}
}
