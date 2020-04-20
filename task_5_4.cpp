#include <iostream>
using namespace std;

enum init
{
	user_init = 1,
	random_init,
	default_init
};

//10. �������� �������, ������������ ������ �� �����, ������������� �
//�������� ������� ������������� �������(�������� �������) ����������� ���������� ���. 
//���� ����� ����� ���������, �� ������� ������������ �� ���. �������� ���� ������� ��������� k.

int& func(int* array, int size)
//�������, ������������ ������ �� �����, ������������� � �������� ������� ����������� ���������� ���
{
	bool* flags = new bool[size] {};	//��� ������. 1 - ����� �� ��������������� ������� ������� ��� �����������, 0 - ���
	unsigned int counter = 1,		 //������� ��� ���������� ������������� ���������
		min_counter = 1;			//� ��� �������� �� ������������ ��������
	int number = array[0], min_index;			//�����, ������������� ����������� ���������� ���

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

		if (i == 0) min_counter = counter;	//�������������� ����������� ���������� ������ ����������
											//�� ����� ����������� ������� ����, �� � �� ������ ��������� ������ �����
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
		cout << "�������� ��������. ��������� ����\t" << endl;
	}
}

bool initialization(int* array, int size, int c)
//������������� �������
{
	switch (c)
	{
	case user_init:
	{
		cout << "\n������� �������� �������(int)\n";
		for (unsigned int i = 0; i < size; i++)
		{
			while (true)
			{
				cin >> array[i];
				if (cin) break;
				cin.clear();
				rewind(stdin);
				cout << "�������� ��������. ��������� ����\t" << endl;
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
	cout << "������� ������ �������:\t";
	size = valid_input(size = 0);
	array = new int[size];

	cout << "�������� ������ �������������:\n"
		<< "1 - � ����������\n"
		<< "2 - ������������� ����������\n"
		<< "3 - ������������� �� ���������\n";

	unsigned int choice;
	cin >> choice;
	bool init  = initialization(array, size, choice);
	cout << endl;

	if (init)
	{
		int number = func(array, size);
		cout << "\n������� �����:\t" << number << endl;

		int k;	 //�������� �� ������� ����� �������� ���������� �������� ������� 
		cout << "������� ����� ��� ������\t";
		k = valid_input(k = 0);
		func(array, size) = k;
		cout << "\n����������� ������:\n";
		for (int i = 0; i < size; i++)	cout << array[i] << ' ';
	}
}
