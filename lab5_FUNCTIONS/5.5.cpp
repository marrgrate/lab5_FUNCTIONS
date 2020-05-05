//Вычислить корень уравнения f (x) = 0 на отрезке [a; b] с точностью eps = 10–6
//используя заданный метод (М = 1 – метод половинного деления, М = 2 – метод
//касательных, М = 3 – метод хорд) для заданных функций. 
//Вычисление корня уравнения оформить в виде функции с функциональным параметром, 
//параметры a, b, eps, s – в виде аргументов по умолчанию. 


#include <iostream>
#include <iomanip>
using namespace std;

float Function1(float x, float s);
float Function2(float x, float s);
void Print(float s, float x, float f, float iter);



 int main()
 {
     float X = 0;
     MetodHord(0, 2, 0, 0, 0, Function1);
     cout << endl;
     MetodHord(-1.5, 1, 0.9, 1.1, 0.05, Function2);
     return 0;
 }

 float Function1(float x, float s)
 {
     return pow((x + 1), 2) - 5;
 }

 float Function2(float x, float s)
 {
     return (float)pow(x, 2) - (float)exp(x) - (float)1.5 * s;
 }

 float MetodHord(float a, float b, float s1, float s2, float d_s,
     float (*func)(float x, float s),
     float eps = 1e-6)
 {
     float X = a;
     int iter = 0;
     cout << "|\tS\t|\tx\t|\tF(x)\t\t|    k_iter\t|" << endl;
     cout << "+---------------+---------------+-----------------------+---------------+" << endl;

     while (true)
     {
         iter = 0;
         do
         {
             X = a - func(a, s1) * (a - b) / (func(a, s1) - func(b, s1));
             iter++;
             if ((func(a, s1) > 0 && func(X, s1) > 0) || (func(a, s1) < 0 && func(X, s1) < 0))
                 a = X;
             else b = X;
         } while (abs(func(X, s1)) >= eps && abs(a - b) >= eps);
         Print(s1, X, func(X, s1), iter);
         s1 += d_s;
         if (s1 >= s2)break;
     }
     cout << "+---------------+---------------+-----------------------+---------------+" << endl;
     return X;
 }

 void Print(float s, float x, float f, float iter)
 {
     cout << "|\t" << s << "\t|     "
         << setw(3) << setprecision(5) << x << setw(3) << "\t|\t"
         << setprecision(4) << setw(5) << f << setw(7);
     cout << "\t|\t" << setw(1) << iter << "\t|" << endl;
 }
