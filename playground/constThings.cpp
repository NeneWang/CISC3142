#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int x{ 5 };
    const int* ptr { &x }; // okay: ptr is pointing to a "const int"
    cout << x << endl; //5
    cout << ptr << endl; //0x61ff08
    // *ptr = 6; // not allowed: we can't change a const value

    return 0;
}