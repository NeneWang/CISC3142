#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // const int x{ 5 };
    // const int* ptr { &x }; // okay: ptr is pointing to a "const int"
    // cout << x << endl; //5
    // cout << ptr << endl; //0x61ff08
    // *ptr = 6; // not allowed: we can't change a const value



    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y

    return 0;
}