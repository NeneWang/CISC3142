#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

#define INPUTFILENAME "sample.txt"

using namespace std;

int main(){

    ifstream inputFile;

    inputFile.open(INPUTFILENAME);

    double sumX=0, sumY=0;
    int countLines=0;
    vector<double> xarr, yarr;
    double x, y;
    string singleLine;

    if(inputFile.is_open()){
        while(inputFile >> y >> x){
            // printf("%f %f\n", x, y);
            countLines++;

            xarr.push_back(x);
            yarr.push_back(y);
            sumX += x;
            sumY += y;
        }
    }
    double meanX = sumX/countLines;
    double meanY = sumY/countLines;

    // Calculate X meanSquares

    double b1x = 0, b1y = 0, b1 = 0, bsqr = 0;
    for (int i = 0; i<countLines ; i++){
        // cout << "Calculated individual: "  << xarr.at(i) - meanX << endl;
        b1x = xarr.at(i) - meanX;
        b1y = yarr.at(i) - meanY;
        b1+=b1x + b1y;
        bsqr += b1x*b1x;
        // printf("b1x: %f, sqr: %f, x elem %f, x-xmean %f,  y- ymean %f, indiiv\n", b1x, bsqr, xarr.at(i), b1x, b1y, b1x-b1y);
    }

    double slope = b1/bsqr;
    double intercept = meanY - slope*meanX;

    // cout << sumX << " " << sumY << endl;
    cout << "\n" << b1x  << " <- x mean : y ->"<< b1y << countLines<< endl;
    printf("Sum of all X: %f, Sum of all Y: %f \nMean X %f, mean Y: %f\nslope: %f, intercept: %f\n", sumX, sumY, meanX, meanY, slope, intercept);

}




