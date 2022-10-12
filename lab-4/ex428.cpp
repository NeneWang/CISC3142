#include <iostream>
#include <vector>

using namespace std;

int main(){

    cout << "Size on bytes\n";
    cout << "char" << " " << sizeof(char) << endl;
    cout << "int" << " " << sizeof(int) << endl;
    cout << "string" << " " << sizeof(string) << endl;
    cout << "float" << " " << sizeof(float) << endl;
    cout << "long" << " " << sizeof(long) << endl;
    cout << "long long" << " " << sizeof(long long) << endl;
    cout << "double" << " " << sizeof(double) << endl;
    cout << "long double" << " " << sizeof(long double) << endl;
    cout << "bool" << " " << sizeof(bool) << endl;
    
    // And so forth: https://learn.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-170
}