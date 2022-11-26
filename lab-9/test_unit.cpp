#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>

#include "MovieProcessor.cpp"
#include "Forecaster.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#include <cstdio>

using namespace std;

void problem1(void)
{
    const string filpath = "film.csv.txt";
    MovieProcessor forecaster(filpath, 2, false);
    forecaster.read();
    forecaster.printStats();
}

void problem2(void){
    ;
}

void test_p4(void)
{
    vector<int> res = p4(2); // Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking value");
    loop_vect(res);
}

TEST_LIST = {
    {"problem1", problem1},
    // {"csvRead", csvRead},
    // {"test_p4", test_p4},
    {0}};