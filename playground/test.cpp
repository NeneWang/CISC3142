#include <iostream>

using namespace std;

int main(){
    extern int kl;
    int ival = 42;
    // int *p = &ival;

    int i = 42;
    int j = 13;
    int *p = &j;

    
    cout << p <<endl; //0x61ff00
    cout << *p <<endl; //13

    int *&r = p;


    
    cout << r <<endl; //0x61ff00
    cout << *r <<endl; //13
    r = &i;
    *r = 15;

    cout << r <<endl; //0x61ff08
    cout << i <<endl; //15
    int &refi = i;
    refi = 30;
    cout << i <<endl; //30
    



    // cout << *r <<endl; //0x61ff08

    cout << &ival <<endl; //0x61ff08
    cout << *p << endl; //42
    cout << ival << endl; //42
    return 0;
}

