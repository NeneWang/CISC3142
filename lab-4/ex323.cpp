#include <iostream>
#include <vector>
using namespace std;

void usingIterator(vector<int> &numbers){
    for (auto it = begin(numbers); it != end(numbers); it++){
        *it *= 2;
    }
}

void printAllVector(vector<int> numbers){
    cout<<endl;
    for(auto num: numbers){
        cout << num << " ";
    }
}

int main(){
    vector<int> numbers(10, 3);
    usingIterator(numbers);
    printAllVector(numbers);
    return 0;
}