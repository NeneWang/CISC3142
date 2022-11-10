#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"
#include "main.cpp"

#include <iostream>
#include <vector>
using namespace std;




void test_p4(void){
    ; 
}

void p1_sets(void){
    Rectangle rect;
    rect.setlength(4);
    TEST_ASSERT(rect.length == 4);
}



TEST_LIST = {
    {"test_p4", test_p4},
    {"p1_setLength", p1_sets},
    {0}};