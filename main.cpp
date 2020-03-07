//
//  main.cpp
//  Lab_2
//
//  Created by Кирилл Броцкий on 22.02.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <locale.h>
#define pr print();
using namespace std;
 double w1[5];
 double w2[5];
 int i;
 string str;

class Vector
{
    int k;
    double *pv;
public:
    const double & operator[] (int index) const
        {
            return pv[index];
        }
    
//    Vector()
//        {
//            pv = 0;
//            k = 0;
//        }
 
    
    Vector(double *ws, int n)
        {
            this->k = n;
            this->pv = new double[n];
        for (int i = 0; i<n; i++)
            this->pv[i] = ws[i];
        }
    
    Vector(const Vector & V)
    { // Конструктор копирования
        k = V.k;
        pv = new double[k];
        for (int i = 0; i < k; i++)
            pv[i] = V.pv[i];
    }

    // Конструктор перемещения
    
    Vector(Vector&& V)  // Параметр - правосторонняя ссылка
        : pv(V.pv), k(V.k)   // Можно инициализировать так
    {
        //p = M.p;  // Или инициализировать так
        //n = M.n;
        // Присвойте данным-членам исходного объекта значения по умолчанию. Это не позволяет деструктору освобождать память
        V.pv = nullptr;
        V.k = 0;
    }
    
    
    Vector() {
    pv = nullptr; k = 0; // Конструктор без параметров, задает "пустой" объект
    }
    double &operator[](int index) // Оператор - функция (перегрузка операции обращения к элементу)
    {
    return pv[index];
    }
    
    
    Vector & operator =(Vector& vec_2)
        {
            k = vec_2.k;
            pv = new double[k];
            for (int i = 0; i<k; i++) pv[i] = vec_2.pv[i];
                return *this;
        }
 
    void print() const // Печать + заменa на перегрузку
        {
            for (int i = 0; i < k; i++)
                std::cout << pv[i] << " ";
            std::cout << std::endl;
        }
 
    ~Vector()
        {
            if (k>0) delete[] pv;
        }
    friend double *operator +(Vector& V1,   double *v2);
};
 
double *operator +(Vector& V1,   double *v2)
    {
        double *p = new double[V1.k];
        for (int i = 0; i<V1.k; i++)
            p[i] = V1.pv[i] + v2[i];
        return p;
    }

void input(){
    ifstream file("input.txt");
    for (i=0;i<5;i++)
    {
        file>>w1[i];
    }
    getline(file, str);
    for (i=0;i<5;i++)
    {
        file>>w2[i];
    }
    file.close();
}

void output(){
    ifstream file("output.txt");
    V1.pr;
    V2.pr;
    for (i=0;i<5;i++)
    {
        fout<<V1[i];
    }
    V3.pr;
    file.close();
}

int main() {
    setlocale(LC_ALL, "rus");
    input();
    Vector V1(w1, 5); // Создаем объект
    Vector V2(w2, 5);
    V1.pr;
    V2.pr;
    printf("\nПерегрузка операции []...\n");
    for (int i = 0; i<5; i++)
        printf(" %.2f ", V1[i]);
    double *w3;
    printf("\n\nПерегрузка операции: +");
    w3 = V1 + w2;
    Vector V3(w3, 6);
    printf("\nCуммированный вектор: ");
    V3.pr;
    output();
    printf("\n");
    return 0;
}
