#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    const int MIN_NUM=3, MAX_NUM=100;
    vector<int> primeNumbers;
    primeNumbers.push_back(2);

    for(int testPrime=MIN_NUM; testPrime< MAX_NUM; testPrime++){
        bool isPrime = true;
        for(int primeNum : primeNumbers){
            if(testPrime % primeNum == 0){
                isPrime = false;
            }
        }
        if(isPrime){
            primeNumbers.push_back(testPrime);
            cout << testPrime << endl;
            // printf("%d added to the prime list\n", testPrime);
            // cout << primeNumbers << endl;
        }

    }

}


