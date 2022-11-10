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


    rect.setwidth(10);
    TEST_ASSERT(rect.width == 10);
}

void p1_calculations(void){
    Rectangle rect;
    rect.setlength(5);
    rect.setwidth(10);
    float perim = rect.perimeter();

    TEST_ASSERT(perim == 5*2 + 2*10);

    float area = rect.area();
    TEST_ASSERT(area = 5*10);

    // rect.show();


    Rectangle anotherRectangle;
    anotherRectangle.setlength(50);
    anotherRectangle.setwidth(1);

    TEST_ASSERT(rect.sameArea(anotherRectangle) == 1);
    TEST_ASSERT(rect.sameArea(anotherRectangle) == true);



}



TEST_LIST = {
    {"test_p4", test_p4},
    {"p1_setLength", p1_sets},
    {"p1_calculations", p1_calculations},
    {0}};