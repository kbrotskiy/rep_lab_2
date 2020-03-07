
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Vector{
    
    double *pv;
    int k;
    
public:
    
    Vector(){
        pv=nullptr;
        k=0;
    }
    
    Vector(double *ws, int n){
        this->k=n;
        this->pv=new double[n];
        for (int i=0;i<n;i++) this->pv[i]=ws[i];
    }
    
    Vector(const Vector & V){
        k=V.k;
        pv=new double[k];
        for (int i=0;i<k;i++) pv[i]=V.pv[i];
    }
    
    Vector(Vector&& V){
        V.pv=nullptr;
        V.k=0;
    }
    
    ~Vector(){
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
};

double *operator +(Vector& V1,   double *v2)
{
    double *p = new double[V1.k];
    for (int i = 0; i<V1.k; i++)
        p[i] = V1.pv[i] + v2[i];
    return p;
}


int main(){
//    int n;
    string str;
    ifstream fin("/Users/kirillbrockij/Library/Mobile Documents/com~apple~CloudDocs/Xcode/БАМОНКА/2 semestr/Lab_2/Lab_2/input.txt");
    double *w1=new double[5];
    for (int i=0;i<5;i++){
        fin>>w1[i];
    }
    double *w2=new double[5];
    getline(fin, str);
    for (int i=0;i<5;i++){
        fin>>w2[i];
    }
    fin.close();
    Vector V1(w1, 5); // Создаем объект
    Vector V2(w2, 5);
    double *w3;
    w3 = V1 + w2;
    Vector V3(w3, 5);
    
    ofstream fout("Output.txt");
    for (int i=0;i<5;i++){
        fout << V3[i] << " ";
    }
    fout <<endl;
    fout.close();
    return 0;
}
