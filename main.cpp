
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vector.h"
using namespace std;

int main(){
    Vector vector1;
    Vector vector2;
    string str;
    ifstream fin("input.txt");
    if (fin.is_open()) {
        fin >> vector1;
    }
    getline(fin, str);
    if (fin.is_open()) {
        fin >> vector2;
    }
    fin.close();
    ofstream fout("Output.txt");
    for (int i=0;i<5;i++){
        fout << V3 << " ";
    }
    fout <<endl;
    fout.close();
    return 0;
}
