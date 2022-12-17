
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
    int INT_MAX = 1000000000;
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

    vector<string> titles;
    for (MovieInformation movieInformation : movieVect){
        titles.push_back(movieInformation.title);
    }
    const string SEARCH_TITLE = "Godfather, The";
    auto it = find(begin(titles), end(titles), SEARCH_TITLE);
    int position = it - begin(titles);
    cout << "\nFound at position: " << position << endl;
    movieVect.at(position).printContent();

    TEST_ASSERT(movieVect.at(position).title == SEARCH_TITLE);

}

void problem4(void){
    // Searching
    const string FILEPATH = "film.csv.txt";
    MovieProcessor movieProcessor(2);
    movieProcessor.read_csv(FILEPATH);

    // Extracting to two vectors
    vector<MovieInformation> movieVect = movieProcessor.movieCollection;
    vector<int> actionMovies, comedyMovies;
    string category_1 = "Action", category_2 = "Comedy";
    for (MovieInformation movie : movieVect){
        if(movie.subject == category_1){
            actionMovies.push_back(movie.year);
            // movie.printContent();
        }
        else if(movie.subject == category_2){
            actionMovies.push_back(movie.year);
            // movie.printContent();
        }

    }

    sort(actionMovies.begin(), actionMovies.end());
    sort(comedyMovies.begin(), comedyMovies.end());

    auto last = unique(actionMovies.begin(),actionMovies.end());
    auto last_2 = unique(comedyMovies.begin(),comedyMovies.end());

    actionMovies.erase(last, actionMovies.end());
    comedyMovies.erase(last_2, comedyMovies.end());
    // for (auto year : actionMovies){
    //     cout << year << endl;
    // }

    bool result = equal(comedyMovies.begin(), comedyMovies.end(), actionMovies.begin());
    if(result){
        cout << "\nAll the years in Action Movie appears in Comdy Movies";
    }else{
        cout << " They dont have years in common";
    }
    


}

TEST_LIST = {
    {"problem0", problem0},
    {"problem1", problem1},
    {"problem2", problem2},
    {"problem3", problem3},
    {"problem4", problem4},
    {0}};