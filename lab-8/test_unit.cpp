#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>

#include "MovieProcessor.cpp"

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
    const string FILEPATH = "film.csv.txt";
    MovieProcessor movieProcessor(FILEPATH, 2, false);
    movieProcessor.read();
    movieProcessor.printStats();
    
}


TEST_LIST = {
    {"problem1", problem1},
    {0}};