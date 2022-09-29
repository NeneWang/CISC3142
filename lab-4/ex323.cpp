#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> numbers(10, 3);

    for(int number : numbers){
        cout << number*2;
    }

    return 0;
}