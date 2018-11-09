
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(10, 10);
    Matrix<int> b(10, 10);
    a.set(6,5,2);
    a.set(6,3,5);
    a.set(6,2,9);
    b.set(6,5,5);
    b.set(1,3,5);
    b.set(5,2,9);
    cout<<a(6,3)<<endl;
    cout<<a(6,1)<<endl;
    cout<<a(6,2)<<endl;
    a+b;
    cout<<a(3,5)<<endl;
    cout<<a(1,3)<<endl;
    cout<<a(5,2)<<endl;
    cout<<a(6,3)<<endl;
    cout<<a(6,5)<<endl;
    cout<<a(6,2)<<endl;


    return 0;
}