
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
//    int n;
    Vector vector1;
    Vector vector2;
    string str;
    ifstream fin("/Users/kirillbrockij/Library/Mobile Documents/com~apple~CloudDocs/Xcode/БАМОНКА/2 semestr/Lab_2/Lab_2/input.txt");
    double *w1=new double[5];
    if (fin.is_open()) {
        fin >> vector1;
    }
    double *w2=new double[5];
    getline(fin, str);
    if (fin.is_open()) {
        fin >> vector2;
    }
    fin.close();
    Vector V1(w1, 5); // Создаем объект
    Vector V2(w2, 5);
    double *w3;
    w3 = V1 + w2;
    Vector V3(w3, 5);

    ofstream fout("Output.txt");
    for (int i=0;i<5;i++){
        fout << V3 << " ";
    }
    fout <<endl;
    fout.close();
    return 0;
}
