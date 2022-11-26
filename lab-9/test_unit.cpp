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

void printForecasts( TemperatureProcessor tempP, const char *TARGET_MONTH);

void problem1(void)
{
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read(true);
}

void problem2(void)
{
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.forecast(monthsNames[0]);

    const char *TARGET_MONTH = "Oct";
    printForecasts(tempP, TARGET_MONTH);
}

void problem3(void)
{
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.to_csv("output.csv", true, false);
}

void inlcude_weighted_average(void)
{
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.to_csv("output_weighted_included.csv", true, true);
}

// test ability to able to forecast other months as well.
void test_forecast_all_months(void)
{
    const string FILEPATH = "weather.csv.txt";
    TemperatureProcessor tempP(FILEPATH, 1);
    tempP.read();
    tempP.forecast(monthsNames[0]);

    const int MONTHSNUMBER = 12;
    const char *monthsNames[MONTHSNUMBER] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int monthIdx = 0; monthIdx < MONTHSNUMBER; monthIdx++)
    {
        printForecasts(tempP, monthsNames[monthIdx]);
    }
}

void printForecasts( TemperatureProcessor tempP, const char *TARGET_MONTH = "Oct" )
{
    int forecasted = tempP.forecast(TARGET_MONTH);
    printf("Forecasted temp using average for: %s is: %d\n", TARGET_MONTH, forecasted);

    int forecastedMovingAverage = tempP.forecast(TARGET_MONTH, pastThreeMonths);
    printf("Forecasted temp using moving average for: %s is: %d\n", TARGET_MONTH, forecastedMovingAverage);

    int forecastWeightedAverage = tempP.forecast(TARGET_MONTH, weightedAverage);
    printf("Forecasted temp using Weighted average for: %s is: %d\n", TARGET_MONTH, forecastWeightedAverage);
}

TEST_LIST = {
    {"problem1", problem1},
    {"problem2", problem2},
    {"problem3", problem3},
    {"inlcude_weighted_average", inlcude_weighted_average},
    {"test_forecast_all_months", test_forecast_all_months},
    // {"csvRead", csvRead},
    {0}};