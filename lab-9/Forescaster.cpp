#include <string>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

class Forecaster
{
public:
    string file;
    Forecaster(string fileIn){
        this->file = fileIn;
    }
    void read()
    {
        ofstream outfile;
        outfile.open("afile.dat");

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