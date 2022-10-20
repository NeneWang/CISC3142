#include <iostream>
#include <vector>

using namespace std;

vector<int> doubleIt(int i){
    vector<int> iv(10,i);

    for(auto it = iv.begin(); it != iv.end(); ++it){
        *it *=2;
        
    }
    return iv;

}

void displayVector(vector<int> v){
    for(auto &el:v){
        cout << el <<endl;
    }
}

int main(){
    // vector<int> vect(3, 2);
    vector<int> sample = doubleIt(2);
    displayVector(sample);

}