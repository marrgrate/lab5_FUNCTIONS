//сортировкой бинарными вставками и сортировкой выбором;

#define size 10000

void sort_bin(int* array)
{
	for (int i = 1; i < size; i++) //перебор всех элементов начиная со второго  
	{
		int x = array[i]; // присвоение переменной х текущего элемента  
		int left = 0; //установка текущих границы для поиска   
		int right = i - 1;

		while (left <= right) //поиск места вставки бинарным поиском  
		{
			int mid = (left + right) / 2;
			if (x < array[mid]) right = mid - 1;
			else left = mid + 1;
		}   // сдвиг элементов после найденного места на 1 позицию вправо  
		for (int j = i - 1; j >= left; j--) array[j + 1] = a[j];
		array[left] = x; //вставка текущего элемента в найденную позицию  
	}
}

void sort_bin(char array)
{

}

void sort_bin(double array)
{

}

void sort_bin(float array)
{

}

void SortSelect(int a[], int size) 
{
	cout << "Selection Sort Mode:\n"; // последовательный перебор всех элементов кроме последнего 
	for (int i=0;i<size-1;i++)   
	{    int min = a[i]; //присвоение переменной минимум текущего элемента  
	int index_min = i; // запоминаем индекс текущего элемента  
					   // поиск минимума в части массива от i+1 до конца   
	for (int j=i+1;j< size;j++)   
		if (a[j] < min)   
		{    min = a[j]; // запоминаем текущий найденный минимум 
	index_min = j; // запоминаем его индекс   
		}  
	//обмен местами текущего элемента и найденного минимального  
	a[index_min] = a[i];   a[i] = min;  
	} 
} 