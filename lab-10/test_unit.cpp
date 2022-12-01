
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
    
    vector<MovieInformation> v = movieProcessor.movieCollection;

    int sumLengths = accumulate(begin(v), end(v), 0, [](const int &x, const MovieInformation &y)
                             { return x + y.length; });



    printf("\nSum of popularity using accumulate isis %d", sumLengths);
    TEST_ASSERT(sumLengths == movieProcessor.totalFilmLength);
}



// void problem2(void){

//     const string FILEPATH = "film.csv.txt";

//     MovieProcessor movieProcessor(2, false);
//     movieProcessor.read_csv(FILEPATH);

//     movieProcessor.printStats();
// }

// void problem3(void){

//     const string FILEPATH = "film.csv.txt";

//     MovieProcessor movieProcessor(2, false);
//     movieProcessor.read_csv(FILEPATH);
//     movieProcessor.to_file("film_stats.txt");

// }

TEST_LIST = {
    {"problem0", problem0},
    {"problem1", problem1},
    // {"problem2", problem2},
    // {"problem3", problem3},
    {0}};