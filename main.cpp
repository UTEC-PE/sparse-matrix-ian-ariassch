
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(3, 3); //esta al reves, es decir hay 3 columnas y 2 filas.
    Matrix<int> b(3, 3);
    a.set(1,2,2);
    a.set(1,2,5);
    a.set(1,2,7);
    a.set(1,3,6);
    a.set(3,2,9);
    b.set(2,1,10);
    b.set(2,2,5);
    b.set(1,2,9);

    a.print();
    cout<<endl;
    b.print();
    cout<<endl;
   Matrix<int> resultado = a-b;
    cout<<endl;
    resultado.print();


    return 0;
}