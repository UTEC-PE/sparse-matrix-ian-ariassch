
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(10, 10);
    a.set(6,5,2);
    a.set(6,3,5);
    a.set(6,2,9);
    cout<<a(6,3)<<endl;
    cout<<a(6,1)<<endl;
    cout<<a(6,2)<<endl;
    a*3;
    cout<<a(6,3)<<endl;
    cout<<a(6,5)<<endl;
    cout<<a(6,2)<<endl;


    return 0;
}