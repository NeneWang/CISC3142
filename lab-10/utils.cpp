#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void loop_vect(vector<T> vect)
{
    for (auto val : vect)
    {
        cout << val << endl;
    }
}

template <typename T>
void printFirsts(vector<T> arr, int to_print)
{

    for (int i = 0; i < to_print; i++)
    {
        printf("\n%d=%s", i, to_string(arr.at(i)).c_str());
    }
}
