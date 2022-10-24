#include <iostream>

#include <vector>

using namespace std;

int main(){
    const int ci = 42;
    const int cj = 10;

    const int *p1 = &ci;
    cout << p1 <<endl;
    p1 = &cj;

    cout << p1 <<endl;
    
}