#include <iostream>

#include <vector>

using namespace std;

int main(){
    const int ci = 42;
    const int cj = 10;

    // const int actually means the type it can save
    const int *p1 = &ci;
    cout << p1 <<endl; //0x61ff08
    p1 = &cj;

    cout << p1 <<endl; //0x61ff08 : Which means it can successfully change the address it is pointing to

    // now this: Shoudn't be able to change where it is pointing at.
    const int *const pc1 = &ci;

    cout << pc1 << endl; //0x61ff04

    // pc1 = &cj; // This will throw Error because you can't modify this one.



}