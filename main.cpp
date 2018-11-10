
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(3, 3);
    Matrix<int> b(3, 3);
    a.set(1,2,2);
    a.set(1,3,5);
    a.set(1,1,9);
    b.set(2,1,10);
    b.set(3,2,5);
    b.set(1,2,9);

    a.print();
    cout<<endl;
    b.print();
    Matrix<int> resultado = a*b;
    cout<<endl;
    resultado.print();


    return 0;
}