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
        string year;
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
            this->year = inString.at(0);

            try
            {
                this->length = stoi(inString.at(1));
            }
            catch (const exception &e)
            {
                this->length = 0;
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
    };


    string fname = "film.csv.txt";

    vector<vector<string>> content;
    vector<MovieInformation> movieCollection;

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
            totalFilmLength += mvInfo.length;
            movieCollection.push_back(mvInfo);
        }
    }
    else
        cout << "Could not open the file\n";

    int collectionSize = movieCollection.size();
    for (int i = 0; i < collectionSize; i++)
    {
        movieCollection.at(i).printContent();
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