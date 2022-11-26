#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

class Forecaster
{
public:
    string file;
    int average;
    int countAll;
    vector<vector<string>> content;


    Forecaster(string fileIn){
        this->file = fileIn;
    }
    void read()
    {
        ifstream ifs(file, ifstream::in);
        char c = ifs.get();
        while (ifs.good())
        {
            cout << c;
            c = ifs.get();
        }

        ifs.close();
    }
};