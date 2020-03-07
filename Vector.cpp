#include "Vector.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 


Vector::Vector(int *p, int n) {
	this->n = n;
	this->p = new int[n];
	for (int i = 0; i < n; i++) this->p[i] = p[i];
}

Vector::Vector() {
	p = nullptr;
	n = 0;
}

Vector::Vector(const Vector & V)
{
	cout << "Copy constructor" << endl;
	n = V.n;
	p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = V.p[i];
}

Vector::Vector(Vector&& V)
	: p(V.p), n(V.n)
{
	cout << "Move constructor" << endl;
	V.p = nullptr;
	V.n = 0;
}

Vector::~Vector() // Деструктор
{
	if (p != nullptr) delete[] p; // Освобождаем память
}

Vector& Vector::operator^(const Vector & vector) {
	int * v = new int[vector.n];
	for (int i = 0; i < vector.n; i++) {
		v[i] = p[i] ^ vector.p[i];
	}
	Vector * result = new Vector(v, vector.n);
	delete[] v;
	return *result;
}


Vector& Vector::operator=(const Vector& v2) // Оператор- функция копирования объекта 
{
	cout << "Assignment copy operator" << endl;
	n = v2.n;
	if (p != nullptr) delete[] p; // Освобождаем память старого вектора
	p = new int[n]; // Выделяем память для нового вектора
	for (int i = 0; i < n; i++) p[i] = v2.p[i];
	return *this; // Возвращаем ссылку на текущий объект
}

Vector& Vector::operator=(Vector&& v2) // Оператор- функция копирования объекта 
{
	cout << "Assignment move operator" << endl;
	n = v2.n;
	if (p != nullptr) delete[] p; // Освобождаем память старого вектора
	p = new int[n]; // Выделяем память для нового вектора
	for (int i = 0; i < n; i++) p[i] = v2.p[i];
	v2.p = nullptr;
	v2.n = 0;
	return *this; // Возвращаем ссылку на текущий объект
}


istream & operator >> (istream& in, Vector & v) {
	string number;
	vector<int> vector;
	while (in >> number)
	{
		vector.push_back(std::stod(number));
	}

	v.p = new int[vector.size()];
	for (int i = 0; i < vector.size(); i++) {
		v.p[i] = vector[i];
	}
	v.n = vector.size();
	return in;
}

ostream & operator << (ostream& out, Vector & vector) {
	for (int i = 0; i < vector.n; i++) {
		out << vector.p[i];
		if (i != vector.n - 1) {
			out << ' ';
		}
	}
	cout << endl;
	return out;
}
