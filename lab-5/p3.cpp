#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define INPUTFILENAME "sample.txt"

using namespace std;

int main(){

    ifstream inputFile;

    inputFile.open(INPUTFILENAME);

    int sumX=0, sumY=0, countLines=0;
    vector<int> xarr, yarr;
    int x, y;
    string singleLine;

    if(inputFile.is_open()){
        while(inputFile){
            getline(inputFile, cin);
            // singleLine >> x >> y; // I guess this doesn't work, Research how to use cin for string
            cin >> x >> y;
            cout << x << " " << y;


            sumX += x;
            sumY += y;
        }
    }

    cout << x << " " << y << endl;

}




