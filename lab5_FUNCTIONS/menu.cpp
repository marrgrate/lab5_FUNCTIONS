#include <iostream>

using namespace std;

#define size 256

// �������� �������, ������������ ������ �� �����, 
// ������������� � �������� ������� ������������� ������� (�������� �������) 
// ����������� ���������� ���. ���� ����� ����� ���������, 
// �� ������� ������������ �� ���. �������� ���� ������� ��������� k. 

void main()
{
	int array[50];
	*array = initialization(array);
	function(array);

}

int initialization(int* array)
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 10 - 5;
	return *array;
}


void print_array()
{

}

int function(int *array)
{
	int number;
	int counter = 0;
	for (int i = 0; i < size; i++)
		number = array[i];
		counter++;
		for(int j = 1; j < size; j++)
			if(array[i])
	return number;
}