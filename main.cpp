//
//  main.cpp
//  Lab_2
//
//  Created by Кирилл Броцкий on 22.02.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#include <iostream>
#include <locale.h>
#define pr print();
 
 
class Vector_1
{
    double *pv;
    int n;
public:
    Vector_1()
        {
            pv = 0;
            n = 0;
        }
 
    Vector_1(double *ws, int n)
        {
            this->n = n;
            this->pv = new double[n];
        for (int i = 0; i<n; i++)
            this->pv[i] = ws[i];
    }
 
     const double & operator[] (int index) const
    {
        return pv[index];
    }
 
    Vector_1 & operator =(Vector_1& vec_2) // Оператор-функция копирования объекта
    {
        n = vec_2.n;
        pv = new double[n];
        for (int i = 0; i<n; i++) pv[i] = vec_2.pv[i];
        return *this;
    }
 
    void print() // Печать вектора (массива)
    {
        printf("\n");
        for (int i = 0; i<n; i++)
            printf(" %.2lf ", pv[i]);
    }
 
    ~Vector_1() // Деструктор
    {
        if (n>0) delete[] pv; // Освобождаем память
    }
 
    friend double *operator +(Vector_1& V1,   double *v2); // Дружественная функция, определенная вне класса. функция результата
};
 
double *operator +(Vector_1& V1,   double *v2)
{
    double *p = new double[V1.n];
    for (int i = 0; i<V1.n; i++)
        p[i] = V1.pv[i] + v2[i];
    return p;
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    double w1[] = { 1.4, 3.2, 4.7, 6.5, 8 };
    Vector_1 V1(w1, 5); // Создаем объект
    double w2[] = { 9, 3.1, 5, 6.6, 14.7 };
    Vector_1 V2(w2, 5);
    printf("\n");
    V1.pr; // Печать объекта
    V2.pr; // Печать объекта
    printf("\n");
    printf("\nПерегрузка операции []...\n");
    for (int i = 0; i<5; i++)
        printf(" %.2f ", V1[i]); // Пример обращения к операции []
    double *w3;
    printf("\n\nПерегрузка операции: +");
    w3 = V1 + w2; // Пример выполнения перегруженной операции +   ,  =
    //w3=operator +(V1, w2);                // второй способ сложения векторов, через оператор-функцию
    Vector_1 V3(w3, 5);
    printf("\nCуммированный вектор: ");
    V3.pr; // Печать полученного объекта
    printf("\n");
    return 0;
}
