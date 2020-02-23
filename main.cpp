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
    int k;
    double *pv;
public:
    const double & operator[] (int index) const
        {
            return pv[index];
        }
    
    Vector_1()
        {
            pv = 0;
            k = 0;
        }
 
    Vector_1(double *ws, int n)
        {
            this->k = n;
            this->pv = new double[n];
        for (int i = 0; i<n; i++)
            this->pv[i] = ws[i];
        }
    
    Vector_1 & operator =(Vector_1& vec_2)
        {
            k = vec_2.k;
            pv = new double[k];
            for (int i = 0; i<k; i++) pv[i] = vec_2.pv[i];
                return *this;
        }
 
    void print()
        {
            printf("\n");
            for (int i = 0; i<k; i++)
                printf(" %.2lf ", pv[i]);
        }
 
    ~Vector_1()
        {
            if (k>0) delete[] pv;
        }
    friend double *operator +(Vector_1& V1,   double *v2);
};
 
double *operator +(Vector_1& V1,   double *v2)
    {
        double *p = new double[V1.k];
        for (int i = 0; i<V1.k; i++)
            p[i] = V1.pv[i] + v2[i];
        return p;
    }
 
int main() {
    setlocale(LC_ALL, "rus");
    double w1[] = { 1.4, 3.2, 4.7, 6.5, 8, 20 };
    Vector_1 V1(w1, 6); // Создаем объект
    double w2[] = { 9, 3.1, 5, 6.6, 14.7, 18 };
    Vector_1 V2(w2, 6);
    V1.pr;
    V2.pr;
    printf("\nПерегрузка операции []...\n");
    for (int i = 0; i<6; i++)
        printf(" %.2f ", V1[i]);
    double *w3;
    printf("\n\nПерегрузка операции: +");
    w3 = V1 + w2;
    Vector_1 V3(w3, 6);
    printf("\nCуммированный вектор: ");
    V3.pr;
    printf("\n");
    return 0;
}
