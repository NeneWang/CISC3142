
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#include <cstdio>

using namespace std;

const char *monthsNames[9] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep"};

struct MonthStats
{

    int month_number;
    int temp;
    int movingAverage;
    string month_name;

    MonthStats(int month_numbers, int temp, int movingAverage){
        this->month_number = month_number;
        this->temp = temp;
        this->movingAverage = movingAverage;
        this->month_name = monthsNames[month_number];
    }

    void printStats(){
        printf("Month n: %d, month: %s, temperature: %d, moving average: %d", month_number, month_name, temp, movingAverage);
    }
};

class TemperatureProcessor
{
    string fname;
    int skiplines;
    int movingScope = 3;
    vector<MonthStats> monthVector;

    TemperatureProcessor(string filein, int skiplines=1)
    {
        this->fname = filein;
        this->skiplines = skiplines;
    }

    // Giving past month vector + lastMonth Temp is able to caluclte the moving average.
    int getMovingAverage( vector<MonthStats> monthVector, int lastMonthTemp ){
        vector<int> toAverage;
        toAverage.push_back(lastMonthTemp);
        int getLast = this->movingScope-1, size = monthVector.size();
        for(int idx; idx<getLast; idx++){
            toAverage.push_back(monthVector[size - idx].temp);
        }
        int average = this->getVectorAverage(toAverage);
        return 0;
    }

    int getVectorAverage(vector<int> vectToaverage){
        int sum = 0, len = vectToaverage.size();

        for(int element : vectToaverage){
            sum+=element;
        }
        return sum/len;
    }

    void read()
    {

        string line, word;
        int row_idx = 0;
        fstream file(fname, ifstream::in);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row_idx++;
                if(row_idx <= skiplines){
                    continue;
                }

                string month_name;
                int month_temperature;
                vector<string> line_content;
                stringstream str(line);

                while (getline(str, word, ';'))
                    line_content.push_back(word);
                

                // TODO: Populate with actual temperature
                int temp = 0;
                int month_number = row_idx - skiplines;
                int movingAverage = this->getMovingAverage(monthVector, temp);
                MonthStats monthSt(month_number, temp, movingAverage);
                cout<<"Created Month stats:" << endl;
                monthSt.printStats();

                monthVector.push_back(monthSt);


            }
        }
    }
};
