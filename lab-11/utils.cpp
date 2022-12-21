#include <vector>
#include <iostream>

using namespace std;

void loop_vect(vector<int> vect)
{
    for (auto val : vect)
    {
        cout << val << " ";
    }
    cout << endl;
}

auto printSquaresData = [](vector<vector<bool>> vectorSquares)
{
    for (auto row : vectorSquares)
    {
        for (auto element : row)
        {
            // printf(" %d ", element);
            cout << element << " ";
        }
        cout << endl;
    }
};