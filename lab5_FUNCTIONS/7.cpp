//����������� ��������� ��������� � ����������� �������;

#define size 10000

void sort_bin(int* array)
{
	for (int i = 1; i < size; i++) //������� ���� ��������� ������� �� �������  
	{
		int x = array[i]; // ���������� ���������� � �������� ��������  
		int left = 0; //��������� ������� ������� ��� ������   
		int right = i - 1;

		while (left <= right) //����� ����� ������� �������� �������  
		{
			int mid = (left + right) / 2;
			if (x < array[mid]) right = mid - 1;
			else left = mid + 1;
		}   // ����� ��������� ����� ���������� ����� �� 1 ������� ������  
		for (int j = i - 1; j >= left; j--) array[j + 1] = a[j];
		array[left] = x; //������� �������� �������� � ��������� �������  
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
	cout << "Selection Sort Mode:\n"; // ���������������� ������� ���� ��������� ����� ���������� 
	for (int i=0;i<size-1;i++)   
	{    int min = a[i]; //���������� ���������� ������� �������� ��������  
	int index_min = i; // ���������� ������ �������� ��������  
					   // ����� �������� � ����� ������� �� i+1 �� �����   
	for (int j=i+1;j< size;j++)   
		if (a[j] < min)   
		{    min = a[j]; // ���������� ������� ��������� ������� 
	index_min = j; // ���������� ��� ������   
		}  
	//����� ������� �������� �������� � ���������� ������������  
	a[index_min] = a[i];   a[i] = min;  
	} 
} 