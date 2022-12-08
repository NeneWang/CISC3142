#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
using namespace std;

#include <new>

void askdynamic()
{
    int i, n;
    int *dynamicpoint;
    cout << "\nHow many numbers would you like to type? ";
    cin >> i;
    dynamicpoint = new (nothrow) int[i];
    if (dynamicpoint == nullptr)
        cout << "Error: memory could not be allocated";
    else
    {
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> dynamicpoint[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
            cout << dynamicpoint[n] << ", ";
        delete[] dynamicpoint;
    }
}

void printingContent(int i){
    cout << "i = " << i << endl;
}

void precedence(){
    int i = 0;
    printingContent(++i); //Prints 1
    i = 0;
    printingContent(i++); //Prints 0
    cout << "________Printing numbers_____" << endl;
    vector<int> numbers(20, 2);
    for (auto it = begin(numbers); it != end(numbers); ++it ){
        ++*it + 20;
        *it++ += 3;
        
    }
    for (auto it = begin(numbers); it != end(numbers); ++it ){
        printingContent(*it);

    }

}

void lambda_func(){
    int i = 2;
    // You need the i for refering to external code.
    auto a = [i](int x){
        cout << i + x << endl;
    };

    a(3);

}

void test_p4(void)
{
    vector<int> res = p4(2); // Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking value");
    loop_vect(res);
}

TEST_LIST = {
    {"askdynamic", askdynamic},
    {"test_p4", test_p4},
    {"precedence", precedence},
    {"lambda_func", lambda_func},
    {0}};