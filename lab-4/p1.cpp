#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    int cost, number_year;
    double inflation;
    string inflationstring;

    cout << "Enter cost of item (int), number of years (int), and inflation (2.3)";
    cin >> cost >> number_year >> inflation;
    
    double cost = calculateCost(cost, inflation, number_year);
    printf("$%f", cost);   


    return 0;
}

double calculateCost(int cost, double inflation, int number_year){
    return cost * pow(inflation/100 + 1,  number_year);
}
