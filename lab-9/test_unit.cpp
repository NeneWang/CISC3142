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
            cout << this->year << SPACE << this->length << SPACE << this->subject << SPACE << this->director << SPACE << this->awards << endl;
        }

        bool hasAward()
        {
            // Returns true if award = Yes

            if (this->awards == "Yes")
            {
                return true;
            }
        }

        int getDecade()
        {
            if (this->year <= 999 || this->year > 9999)
            {
                printf("Possible error in the code? year was %d\n", this->year);
                this->printContent();
                cout << endl;
            }
            int decade = this->year / 10;
            return decade * 10;
        }
    };

    string fname = "film.csv.txt";

    vector<vector<string>> content;
    vector<MovieInformation> movieCollection;
    map<int, int[2]> LenCountPerYear;
    map<string, int> directorsPerGenre;

    vector<string> row;
    string line, word;

    int totalFilmLength = 0, row_idx = 0;
    const int SKIPFIRSTS = 2; //Skips the first line

    fstream file(fname, ifstream::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row_idx++;
            if(row_idx <= SKIPFIRSTS){
                continue;
            }

            row.clear();

            stringstream str(line);

            while (getline(str, word, ';'))
                row.push_back(word);
            MovieInformation mvInfo(row);
            content.push_back(row);

            int movieLen = mvInfo.length;
            int decade = mvInfo.getDecade();
            string genre = mvInfo.subject;

            // Add to the decade
            totalFilmLength += movieLen;

            if (LenCountPerYear.find(decade) != LenCountPerYear.end())
            {
                // printf("Addint to decade: %d with Length %d and length %d ", decade, descadeCount[decade], movieLen);
                LenCountPerYear[decade][0] += 1;
                LenCountPerYear[decade][1] += movieLen;
            }
            else
            {
                LenCountPerYear[decade][0] = 1;
                LenCountPerYear[decade][1] = movieLen;
            }

            // Add to the Directors
            if (directorsPerGenre.find(genre) != directorsPerGenre.end())
            {
                directorsPerGenre[genre] += mvInfo.hasAward() ? 1 : 0;
            }
            else
            {
                // printf("New genre %s found", genre);
                // cout << genre;
                directorsPerGenre[genre] = mvInfo.hasAward() ? 1 : 0;
            }
            // directorsPerGenre[]

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

    // Print movies Average Length per genre
    for (const auto &decadeData : LenCountPerYear)
    {
        printf("Decades: %ds average length %d, count %d\n", decadeData.first, decadeData.second[1] / decadeData.second[0], decadeData.second[0]);
    }

    // Print moviews amount moviews with awards per genre
    for (const auto &genreAwardData : directorsPerGenre)
    {
        printf("Genre: %s, Awards: %d\n", genreAwardData.first.c_str(), genreAwardData.second);
    }

    printf("Total Length: %d, average length %d\n", totalFilmLength, collectionSize);
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