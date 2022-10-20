#include <iostream>
using namespace std;

int main(){
 
double  a = - 30 * 3 + 21.0 / 5; // -90 + 4 -> -85.8 instead
double b = - 30 + 3 * 21.0 / 5; // -18 -> -17.4 instead
double c =  30 / 3 * 21 % 5; // 0
double d = - 30 / 3 * 21 % 4; // -2

cout << a << endl<< b << endl << c << endl << d << endl;

cout << 3 + 2*1.1 << endl;

}





