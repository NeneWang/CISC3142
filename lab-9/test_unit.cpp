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
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read(true);
    
    
}

void problem2(void){
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.forecast(monthsNames[0]);
    
    const char* TARGET_MONTH = "Oct";
    int forecasted = tempP.forecast(TARGET_MONTH);
    printf("Forecasted temp using average for: %s is: %d\n", TARGET_MONTH, forecasted);

    
    int forecastedMovingAverage = tempP.forecast(TARGET_MONTH, pastThreeMonths);
    printf("Forecasted temp using moving average for: %s is: %d\n", TARGET_MONTH, forecastedMovingAverage);

    int forecastWeightedAverage = tempP.forecast(TARGET_MONTH, weightedAverage);
    printf("Forecasted temp using Weighted average for: %s is: %d\n", TARGET_MONTH, forecastWeightedAverage);
}


void problem3(void){
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.to_csv("output.csv", true, false);
    
}





TEST_LIST = {
    {"problem1", problem1},
    {"problem2", problem2},
    {"problem3", problem3},
    // {"csvRead", csvRead},
    {0}};