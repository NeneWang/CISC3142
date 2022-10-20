#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    int cost, number_year;
    double inflation;
    string inflationstring;
    // TODO: Request the input for cost, number of years and inflation rate in percentage e.g. 5 -> 0.05

    cout << "Enter cost of item (int), number of years (int), and inflation (2.3)";
    cin >> cost >> number_year >> inflation;
    
    // TODO: Calculate future price
    double cost = calculateCost(cost, inflation, number_year);
    printf("$%f", cost);
    


    return 0;
}

double calculateCost(int cost, double inflation, int number_year){
    return cost * pow(inflation/100 + 1,  number_year);
}
