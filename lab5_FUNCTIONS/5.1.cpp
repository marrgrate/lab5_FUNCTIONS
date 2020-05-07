//Выполнить задание, оформив его через функции. Передачу массивов в функции
//организовать несколькими способами.
//Получить квадратную матрицу порядка n, элементами которой являются
//заданные числа а 1, ..., а nn, расположенные в ней по спирали(см.схему на рисунке).

//43 44 45 46 47 48 49
//42 21 22 23 24 25 26
//41 20  7  8  9 10 27
//40 19  6  1  2 11 28
//39 18  5  4  3 12 29
//38 17 16 15 14 13 30
//37 36 35 34 33 32 31

#include <iostream>
#include <iomanip>

const int n = 5;

enum Direction
{
	down = 0,
	left,
	up,
	right
};

using namespace std;
void init_zero(int mx[][n]);
void print_matrix(int mx[][n]);
void Right(int mx[][n], int& i, int& j, int& value, int& dir);
void Left(int (*mx)[n], int& i, int& j, int& value, int& dir);
void Up(int (&mx)[n][n], int& i, int& j, int& value, int& dir);
void Down(int (&mx)[n][n], int& i, int& j, int& value, int& dir);

int main()
{
	int mx[n][n];

	init_zero(mx);
	int ind = n / 2;
	int value = 1;
	int i = ind, j = ind;
	mx[i][j++] = value;
	value++;
	int direction = down;
	while(value < n*n)
	{
		Down(mx, i, j, value, direction);
		Left(mx, i, j, value, direction);
		Up(mx, i, j, value, direction);
		Right(mx, i, j, value, direction);
	}
	print_matrix(mx);
	return 0;
}

bool check_right_element(int mx[][n], int &i, int &j, int dir)
{
	if (dir == down)
		if (mx[i][j - 1] == 0) return false;
	if (dir == 1)
		if (mx[i - 1][j] == 0) return false; 
	if (dir == 2)
		if (mx[i][j + 1] == 0) return false; 
	if (dir == 3)
		if (mx[i + 1][j] == 0) return false;		
	return true;
}
void change_direction(int& dir)
{
	if (dir == 3) dir = 0;
	else dir++;
}
void Down(int (&mx)[n][n], int& i, int& j, int& value, int& dir)
{
	while (check_right_element(mx, i, j, dir))
	{
		mx[i++][j] = value;
		value++;
	}

	change_direction(dir);
}
void Up(int (&mx)[n][n], int& i, int& j, int& value, int& dir)
{
	while (check_right_element(mx, i, j, dir))
	{
		mx[i--][j] = value;
		value++;
	}
	change_direction(dir);
}
void Right(int mx[][n], int& i, int& j, int& value, int& dir)
{
	do
	{
		mx[i][j++] = value;
		value++;
		if (value > n * n) return;
	}while (check_right_element(mx, i, j, dir));
	change_direction(dir);
}
void Left(int (*mx)[n], int& i, int& j, int& value, int& dir)
{
	while (check_right_element(mx, i, j, dir))
	{
		mx[i][j--] = value;
		value++;
	}

	change_direction(dir);
}
void print_matrix(int mx[][n])
{
	cout << '\t' << "MATRIX\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(3) << mx[i][j];
		cout << endl;
	}
}
void init_zero(int mx[][n])
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			mx[i][j] = 0;
}
