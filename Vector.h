#pragma once
#include <iostream>

using namespace std;

class Vector // Класс- вектор
{
	int *p;
	int n;
public:
	Vector(double *ws, int n);
	Vector();
	Vector(const Vector & V);
	Vector(Vector&& V);
	~Vector();
        double & operator[](int index);
	Vector & operator=(Vector& vec2);
	friend double *operator +(Vector& V1,   double *v2);
        friend istream& operator>>(istream& in, Vector& vector);
	friend ofstream& operator<<(ofstream& out, Vector& vector);
	double *operator +(Vector& V1,   double *v2);
};
