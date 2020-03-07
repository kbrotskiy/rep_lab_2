#pragma once
#include <iostream>

using namespace std;

class Vector // Класс- вектор
{
	int *p;
	int n;
public:
	Vector(int *p, int n);
	Vector();
	Vector(const Vector & vector);
	Vector(Vector && vector);
	~Vector();
	Vector & operator=(const Vector& vector);
	Vector & operator=(Vector&& vector);
	Vector & operator^(const Vector & vector);
	friend istream & operator>> (istream& in, Vector & vector);
	friend ostream & operator<< (ostream& out, Vector & vector);
};
