#include "5.7_func.h"


//Дан массив чисел произвольной длины. Отсортировать массив заданными
//методами :
//сортировкой бинарными вставками и сортировкой выбором;

//Для каждого метода сортировки определить число сравнений и перемещений(перестановок с одного места на другое) элементов в процессе выполнения программы.
//Сравнить экспериментальные результаты с известными теоретическими оценками этих показателей для заданных методов сортировки.
//Обеспечить перегрузку и шаблоны необходимых функций для выполнения задания с типами элементов массивов char, int, float, double.

int main()
{
    int size = 10;
    int* I = new int[size];
    int* I_copy = new int[size];

    cout << endl << "\nRANDOM" << endl;

    initArrayRandom(I, size);
    copy(I, I_copy, size);
    printArray(I, size);
    cout << "\nSelection sort:\n";
    SelectionSort(I, size);
    printArray(I, size);
    cout << "\nBinary sort:\n";
    BinarySort(I_copy, size);
    printArray(I_copy, size);

    cout << endl << "\nDESCENDING" << endl;
    initArrayDescendingOrder(I, size);
    copy(I, I_copy, size);
    printArray(I, size);
    cout << "\nSelection sort:\n";
    SelectionSort(I, size);
    printArray(I, size);
    cout << "\nBinary sort:\n";
    BinarySort(I_copy, size);
    printArray(I_copy, size);

    cout << endl << "\nASCENDING" << endl;
    initArrayAscendingOrder(I, size);
    copy(I, I_copy, size);
    cout << endl;
    printArray(I, size);
    cout << "\nSelection sort:\n";
    SelectionSort(I, size);
    printArray(I, size);
    cout << "\nBinary sort:\n";
    BinarySort(I_copy, size);
    printArray(I_copy, size);

    delete[] I;
    delete[] I_copy;
    return 0;
}

