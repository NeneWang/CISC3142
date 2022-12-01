
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

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
    bool debug = false;

    MovieInformation(vector<string> inString, bool debug = false)
    {
        this->debug = debug;
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

        if(this->debug){
            this->printContent();
        }
    }

    void printContent()
    {
        // printf("%s %s %s", this->year, this->length, this->subject);
        const string SPACE = " ";
        cout << " Year " << this->year << SPACE << "lenght " <<  this->length << SPACE << "Subject " <<  this->subject << SPACE << "director " <<  this->director << SPACE <<"awards " <<   this->awards << endl;
        

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
        if ((this->year <= 999 || this->year > 9999) && this->debug)
        {
            printf("Possible error in the code? year was %d\n", this->year);
            this->printContent();
            cout << endl;
        }
        int decade = this->year / 10;
        return decade * 10;
    }
};

class MovieProcessor
{
public:
    string fname = "film.csv.txt";
    vector<vector<string>> content;
    vector<MovieInformation> movieCollection;
    map<int, int[2]> LenCountPerYear;
    map<string, int> directorsPerGenre;
    bool debug = false;
    vector<string> row;

    int totalFilmLength = 0, row_idx = 0;
    int SKIPFIRSTS = 2; // Skips the first line

    MovieProcessor(int skipFirsts = 2, bool debug = false)
    {
        this->SKIPFIRSTS = skipFirsts;
        this->debug = debug;
    }
    void read_csv(string fileIn)
    {

        this->fname = fileIn;
        string line, word;
        fstream file(fname, ifstream::in);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row_idx++;
                if (row_idx <= SKIPFIRSTS)
                {
                    continue;
                }

                row.clear();

                stringstream str(line);

                while (getline(str, word, ';'))
                    row.push_back(word);
                MovieInformation mvInfo(row, this->debug);
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
                    directorsPerGenre[genre] = mvInfo.hasAward() ? 1 : 0;
                }
                // directorsPerGenre[]

                movieCollection.push_back(mvInfo);
            }
        }
        else
            cout << "Could not open the file\n";
    }

    void printSampleCollection(int count = 10)
    {
        int collectionSize = movieCollection.size();
        if (count > collectionSize)
        {
            count = collectionSize;
        }
        for (int i = 0; i < count; i++)
        {
            movieCollection.at(i).printContent();
        }
    }

    void printStats()
    {

        int collectionSize = movieCollection.size();
        
        
        printf("\nAverage length %d", totalFilmLength / collectionSize);

        for (const auto &decadeData : LenCountPerYear)
        {   
            if(decadeData.first == 0){
                continue;
            }
            printf("\nDecades: %ds average length %d, count %d", decadeData.first, decadeData.second[1] / decadeData.second[0], decadeData.second[0]);
        }

        // Print moviews amount moviews with awards per genre
        for (const auto &genreAwardData : directorsPerGenre)
        {
            
            if(genreAwardData.first == ""){
                continue;
            }
            printf("\nGenre: %s, Awards: %d", genreAwardData.first.c_str(), genreAwardData.second);
        }

    }

    void to_file(string filename)
    {
        
        ofstream writeFile;
        writeFile.open(filename);

        int collectionSize = movieCollection.size();
        
        
        // printf("\nAverage length %d", totalFilmLength / collectionSize);

        writeFile << "\nAverge Lenngth " << totalFilmLength / collectionSize;

        for (const auto &decadeData : LenCountPerYear)
        {   
            if(decadeData.first == 0){
                continue;
            }
            // printf("\nDecades: %ds average length %d, count %d", decadeData.first, decadeData.second[1] / decadeData.second[0], decadeData.second[0]);
            writeFile << "\n Decades: " << decadeData.first << " average length " << decadeData.second[1] / decadeData.second[0] << " count " << decadeData.second[0];
        }

        // Print moviews amount moviews with awards per genre
        for (const auto &genreAwardData : directorsPerGenre)
        {
            
            if(genreAwardData.first == ""){
                continue;
            }

            // printf("\nGenre: %s, Awards: %d", genreAwardData.first.c_str(), genreAwardData.second);
            writeFile << "\n Genre " << genreAwardData.first.c_str() << ", Awards: " << genreAwardData.second;
        }

        
        writeFile.close();

    }

};
