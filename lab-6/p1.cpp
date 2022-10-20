#include <iostream>
#include <cstdio>

using namespace std;

namespace p1{

int main(){
    int result = 0;
    long enterInput, iterateInput;
    cin >> enterInput;
    iterateInput = enterInput;
    while(iterateInput>0){
        int lastDigit = iterateInput%10;
        iterateInput/=10;
        result+=lastDigit;
    }
    printf("Sum of a digits of the number %ld is %d\n", enterInput, result);
}}