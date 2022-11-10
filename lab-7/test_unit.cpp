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


    
    Rectangle distinctRectangle;
    distinctRectangle.setlength(25);
    distinctRectangle.setwidth(4);

    TEST_ASSERT(rect.sameArea(distinctRectangle) == 0);
    TEST_ASSERT(rect.sameArea(distinctRectangle) == false);

}

void p1_run_sub_2(){
    P1_subproblem2();
 
}


void p1_run_sub_3(){
 
    P1_subproblem3();
}

void p2_test_1(){
    Sample sam1 = Sample();
    TEST_ASSERT(sam1.getX() == 1);
    TEST_ASSERT(sam1.getY() == 0);

}

void p2_test_2(){
    Sample sam1 = Sample(10);
    TEST_ASSERT(sam1.getX() == 10);
    TEST_ASSERT(sam1.getY() == 0);

}

void p2_test_3(){
    Sample sam1 = Sample(20, 30);
    TEST_ASSERT(sam1.getX() == 20);
    TEST_ASSERT(sam1.getY() == 30);

}


void p2_test_4(){
    double doblY = 30.12;
    Sample sam1 = Sample(20, doblY);
    TEST_ASSERT(sam1.getX() == 20);

    // cout<<"My y is: " << sam1.getY();
    TEST_ASSERT(sam1.getY() == 30.12);

}


void p3(){
    P3();
}

TEST_LIST = {
    {"test_p4", test_p4},
    {"p1_setLength", p1_sets},
    {"p1_calculations", p1_calculations},
    {"p1_run_subproblems\n p1_run_sub_2", p1_run_sub_2},
    {"p1_run_sub_2", p1_run_sub_3},
    
    {"p2_test_1", p2_test_1},
    {"p2_test_2", p2_test_2},
    {"p2_test_3", p2_test_3},
    {"p2_test_4", p2_test_4},
    
    {"p3", p3},
    {0}};