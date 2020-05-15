#pragma once
#include <iostream>
using namespace std;

void initArrayAscendingOrder(char* array, int size);
void initArrayAscendingOrder(int* array, int size);
void initArrayAscendingOrder(float* array, int size);
void initArrayAscendingOrder(double* array, int size);

void initArrayDescendingOrder(char* array, int size);
void initArrayDescendingOrder(int* array, int size);
void initArrayDescendingOrder(float* array, int size);
void initArrayDescendingOrder(double* array, int size);

void initArrayRandom(char* array, int size);
void initArrayRandom(int* array, int size);
void initArrayRandom(float* array, int size);
void initArrayRandom(double* array, int size);

template<typename T> 
void copy(T* A, T* B, const int size)
{
    for (int i = 0; i < size; i++)
        B[i] = A[i];
}
template<class T>
void printArray(T* array, int array_size)
{
    for (int i = 0; i < array_size; i++)
        cout << array[i] << ' ';
    cout << endl;
}
template<class T>
void BinarySort(T* array, int size)
{
    T x;
    int left;
    int right;
    int mid;
    int cmp = 0, rplc = 0;
    for (int i = 1; i < size; i++) //перебор всех элементов начиная со второго
    {
        T x = array[i]; // присвоение переменной х текущего элемента
        left = 0; //установка текущих границы для поиска
        right = i - 1;
        while (left <= right) //поиск места вставки бинарным поиском
        {       
            int mid = (left + right) / 2;
            
            if (x < array[mid] & cmp++) right = mid - 1;
            else left = mid + 1;
        }
        // сдвиг элементов после найденного места на 1 позицию вправо
        for (int j = i - 1; j >= left; j--)
        {
            array[j + 1] = array[j];
            //rplc++;
        }
        array[left] = x; //вставка текущего элемента в найденную позицию
        rplc++;
    }
    cout << "cmp = " << cmp << ", rplc = " << rplc 
        << ", theoretical complexity = " << size*log(size) << endl;
}
template<class T>
void SelectionSort(T* array_ptr, int size)
{
    int cmp = 0, rplc = 0;
    for (int repeat_counter = 0; repeat_counter < size; repeat_counter++)
    {
        T temp = array_ptr[0];
        for (int element_counter = repeat_counter + 1; element_counter < size; element_counter++)
        {
            cmp++;
            if (array_ptr[repeat_counter] > array_ptr[element_counter])
            {
                temp = array_ptr[repeat_counter];
                array_ptr[repeat_counter] = array_ptr[element_counter];
                array_ptr[element_counter] = temp;
                rplc++;
            }
        }
    }
    cout << "cmp = " << cmp << ", rplc = " << rplc 
        << ", theoretical complexity = " << size*size << endl;
}

