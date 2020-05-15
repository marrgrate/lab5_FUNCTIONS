#include "5.7_func.h"

void initArrayAscendingOrder(char* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = 'a' + i;
}
void initArrayAscendingOrder(int* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i;
}
void initArrayAscendingOrder(float* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i + pow(i, -i);
}
void initArrayAscendingOrder(double* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i + pow(1e-1, i);
}

void initArrayDescendingOrder(char* array, int size)
{
    for (int i = size - 1; i >= 0; i--)
        array[i] = 'a' + size - i;
}
void initArrayDescendingOrder(int* array, int size)
{
    for (int i = size - 1; i >= 0; i--)
        array[i] = size - i;
}
void initArrayDescendingOrder(float* array, int size)
{
    for (int i = size - 1; i >= 0; i--)
        array[i] = size - i + pow(0.1, i);
}
void initArrayDescendingOrder(double* array, int size)
{
    for (int i = size - 1; i >= 0; i--)
        array[i] = size - i + pow(1e-1, i);
}

void initArrayRandom(char* array, int size)
{
    for (short i = 0; i < size; i++)
        array[i] = 'a' + rand() % size;
}
void initArrayRandom(int* array, int size)
{
    for (short i = 0; i < size; i++)
        array[i] = rand() % size;
}
void initArrayRandom(float* array, int size)
{
    for (short i = 0; i < size; i++)
        array[i] = rand() % size + pow(1e-2, i);
}
void initArrayRandom(double* array, int size)
{
    for (short i = 0; i < size; i++)
        array[i] = rand() % size + pow(1e-3, i);
}
