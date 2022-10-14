#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define INPUTFILENAME "sample.txt"

using namespace std;

int main(){

    ifstream inputFile;

    inputFile.open(INPUTFILENAME);

    double sumX=0, sumY=0, countLines=0;
    vector<double> xarr, yarr;
    double x, y;
    string singleLine;

    if(inputFile.is_open()){
        while(inputFile){
            getline(inputFile, singleLine);
            // singleLine >> x >> y; // I guess this doesn't work, Research how to use cin for string
            sscanf(singleLine, "%f %f", x, y);
            printf("%f %f", x, y)


            sumX += x;
            sumY += y;
        }
    }

    cout << x << " " << y << endl;

}




