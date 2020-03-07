#include "Vector.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 


    Vector::Vector(){
        pv=nullptr;
        k=0;
    }
    
    Vector::Vector(double *ws, int n){
        this->k=n;
        this->pv=new double[n];
        for (int i=0;i<n;i++) this->pv[i]=ws[i];
    }
    
    Vector::Vector(const Vector & V){
        k=V.k;
        pv=new double[k];
        for (int i=0;i<k;i++) pv[i]=V.pv[i];
    }
    
    Vector::Vector(Vector&& V){
        V.pv=nullptr;
        V.k=0;
    }
    
    Vector::~Vector(){
        if (pv!=nullptr) delete[]pv;
    }
    
    double & operator[](int index){
        return pv[index];
    }
    
    Vector & operator=(Vector& vec2){
        k=vec2.k;
        if (pv!=nullptr) delete[] pv;
        pv=new double[k];
        for (int i=0;i<k;i++){
            pv[i]=vec2.pv[i];
        }
        return *this;
    }
    friend double *operator +(Vector& V1,   double *v2);
    friend istream& operator>>(istream& in, Vector& vector);
};

double *operator +(Vector& V1,   double *v2)
{
    double *p = new double[V1.k];
    for (int i = 0; i<V1.k; i++)
        p[i] = V1.pv[i] + v2[i];
    return p;
}

istream& operator>>(istream& in, Vector& vector) {
    vector.pv=new double[5];
    vector.k = 5;
    for (int i = 0; i<5; i++) {
        in >> vector[i];
    }
    return in;
}

ofstream& operator<<(ofstream& out, Vector& vector) {
    for (int i = 0; i<5; i++) {
        out << vector[i];
    }
    return out;
}
