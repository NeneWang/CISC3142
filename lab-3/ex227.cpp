#include <iostream>

using namespace std;

int main()
{
    // int i2 = -1, &intRef = 0; // Error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    int i2 = -1;
    int *const p2 = &i2;                 // This will only work if i2 had been successfully created
    const int i = -1, &r = 0, &zero = 0; // THIS IS LEGAL, only CONST can point to a value; Surprisingly r and zero dont point to the same address

    const int *const p3 = &i2;
    const int *p1 = &i2;
    // // Valid p1 is a pointer that points to the address of i2. P1 has a base type declaration of ocnst int; which means that it canot change the address it points to.

    // const int &const r2;
    // const int i2 = i, &r = i;

    // cout << r << endl;
    // cout << &r << endl;    // 0x7ff7b727365c
    // cout << &zero << endl; // 0x7ff7b727364c
}