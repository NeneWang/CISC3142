#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>

#include "Forescaster.cpp"

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
    const string filpath = "film.csv.txt";
    Forecaster forecaster(filpath);
    forecaster.read();
}

void csvRead()
{

    struct MovieInformation
    {
        int year;
        int length;
        string title;
        string subject;
        string actor;
        string actress;
        string director;
        string popularity;
        string awards;
        string image;

        MovieInformation(vector<string> inString)
        {

            try
            {
                this->length = stoi(inString.at(1));
                this->year = stoi(inString.at(0));
            }
            catch (const exception &e)
            {
                this->length = 0;
                this->year = 0;
            }
            this->title = inString.at(2);
            this->subject = inString.at(3);
            this->actor = inString.at(4);
            this->actress = inString.at(5);
            this->director = inString.at(6);
            this->popularity = inString.at(7);
            this->awards = inString.at(8);
            this->image = inString.at(9);
        }

        void printContent()
        {
            // printf("%s %s %s", this->year, this->length, this->subject);
            const string SPACE = " ";
            cout << this->year << SPACE << this->length << SPACE << this->actor << endl;
        }

        int getDecade()
        {
            if (this->year <= 999 || this->year > 9999)
            {
                printf("Possible error in the code? year was %d\n", this->year);
            }
            int decade =  this->year / 10;
            return decade * 10;
        }
    };

    string fname = "film.csv.txt";

    vector<vector<string>> content;
    vector<MovieInformation> movieCollection;
    map<int, int> descadeCount;

    vector<string> row;
    string line, word;

    int totalFilmLength = 0;

    fstream file(fname, ifstream::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ';'))
                row.push_back(word);
            MovieInformation mvInfo(row);
            content.push_back(row);

            int movieLen = mvInfo.length;
            int decade = mvInfo.getDecade();

            totalFilmLength += movieLen;

            if (descadeCount.find(decade) != descadeCount.end())
            {
                printf("Addint to decade: %d with Length %d and length %d ", decade, descadeCount[decade], movieLen);
                descadeCount[decade] += movieLen;
            }
            else
            {
                descadeCount[decade] = 0;
            }

            movieCollection.push_back(mvInfo);
        }
    }
    else
        cout << "Could not open the file\n";

    int collectionSize = movieCollection.size();
    for (int i = 0; i < 10; i++)
    {
        movieCollection.at(i).printContent();
    }

    for (const auto &decadeData : descadeCount)
    {
        std::cout << decadeData.first << "\n";
    }

    printf("Total Length: %d, average length %d", totalFilmLength, collectionSize);
}

void test_p4(void)
{
    vector<int> res = p4(2); // Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking value");
    loop_vect(res);
}

TEST_LIST = {
    // {"problem1", problem1},
    {"csvRead", csvRead},
    // {"test_p4", test_p4},
    {0}};