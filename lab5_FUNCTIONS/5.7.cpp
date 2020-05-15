#include "5.7_func.h"


//��� ������ ����� ������������ �����. ������������� ������ ���������
//�������� :
//����������� ��������� ��������� � ����������� �������;

//��� ������� ������ ���������� ���������� ����� ��������� � �����������(������������ � ������ ����� �� ������) ��������� � �������� ���������� ���������.
//�������� ����������������� ���������� � ���������� �������������� �������� ���� ����������� ��� �������� ������� ����������.
//���������� ���������� � ������� ����������� ������� ��� ���������� ������� � ������ ��������� �������� char, int, float, double.

int main()
{
    int size = 10;
    int* I = new int[size];
    int* I_copy = new int[size];
    char* C = new char[size];
    char* C_copy = new char[size];

    cout << endl << "\nCHAR" << endl;
    initArrayRandom(C, size);
    copy(C, C_copy, size);

    printArray(C, size);
    cout << "\nSelection sort:\n";
    SelectionSort(C, size);
 
    printArray(C, size);
    cout << "\nBinary sort:\n";
    BinarySort(C_copy, size);
    printArray(C_copy, size);

    cout << endl << "\nINT" << endl;
    initArrayDescendingOrder(I, size);
    copy(I, I_copy, size);
    printArray(I, size);

    cout << "\nSelection sort:\n";
    SelectionSort(I, size);
    printArray(I, size);

    cout << "\nBinary sort:\n";
    BinarySort(I_copy, size);
    printArray(I_copy, size);

    delete[] I;
    delete[] C;
    delete[] I_copy;
    delete[] C_copy;
    return 0;
}

