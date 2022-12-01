
#include <algorithm>
#include <numeric>
#include <iterator>
#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>

#include "MovieProcessor.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#include <cstdio>

using namespace std;

void problem0(void)
{
    const string FILEPATH = "film.csv.txt";

    MovieProcessor movieProcessor(2);
    movieProcessor.read_csv(FILEPATH);
    cout << "\nSample: " << endl;
    movieProcessor.printSampleCollection();
}

void problem1(void)
{
    // Sums of popularity
    const string FILEPATH = "film.csv.txt";
    MovieProcessor movieProcessor(2);
    movieProcessor.read_csv(FILEPATH);
    
    vector<MovieInformation> movieVect = movieProcessor.movieCollection;

    int sumLengths = accumulate(begin(movieVect), end(movieVect), 0, [](const int &x, const MovieInformation &y)
                             { return x + y.length; });

    printf("\nSum of popularity using accumulate isis %d", sumLengths);
    TEST_ASSERT(sumLengths == movieProcessor.totalFilmLength);
    
}





void problem2(void){

    const string FILEPATH = "film.csv.txt";
    MovieProcessor movieProcessor(2);
    movieProcessor.read_csv(FILEPATH);
    
    vector<MovieInformation> movieVect = movieProcessor.movieCollection;


    sort(movieVect.begin(), movieVect.end(), [](MovieInformation a, MovieInformation b) {
        return a.length > b.length;
    });

    // Check if they are sorted by length
    int prev = INT_MAX;
    for (MovieInformation mvInfo: movieVect){
        TEST_ASSERT(mvInfo.length <= prev);
        prev = mvInfo.length;
    }
}

void problem3(void){

    // Searching
    const string FILEPATH = "film.csv.txt";
    MovieProcessor movieProcessor(2);
    movieProcessor.read_csv(FILEPATH);
    
    vector<MovieInformation> movieVect = movieProcessor.movieCollection;
    // Godfather, The
    string title_search = "Godfather, The";

    find(movieVect.begin(), movieVect.end(), [](MovieInformation a) {
        return a.title == "Godfather, The";
    });

    // Check if they are sorted by length
    // int prev = INT_MAX;
    // for (MovieInformation mvInfo: movieVect){
    //     TEST_ASSERT(mvInfo.length <= prev);
    //     prev = mvInfo.length;
    // }

}

TEST_LIST = {
    {"problem0", problem0},
    {"problem1", problem1},
    // {"problem2", problem2},
    // {"problem3", problem3},
    {0}};