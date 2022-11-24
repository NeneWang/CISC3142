#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
using namespace std;

#include "Forescaster.cpp"



void problem1(void){
    const string filpath="film.csv.txt";
    Forecaster forecaster(filpath);
    forecaster.read()
}


void test_p4(void){
    vector<int> res = p4(2); //Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking value");
    loop_vect(res);   
}


TEST_LIST = {
    {"problem1", problem1},
    {"test_p4", test_p4},
    {0}};