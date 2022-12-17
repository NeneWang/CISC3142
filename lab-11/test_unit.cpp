#include "acutest.hpp"
#include "act-nelson.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
using namespace std;

#include <new>

void askdynamic()
{
    int i, n;
    int *dynamicpoint;
    cout << "\nHow many numbers would you like to type? ";
    cin >> i;
    dynamicpoint = new (nothrow) int[i];
    if (dynamicpoint == nullptr)
        cout << "Error: memory could not be allocated";
    else
    {
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> dynamicpoint[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
            cout << dynamicpoint[n] << ", ";
        delete[] dynamicpoint;
    }
}

void printingContent(int i)
{
    cout << "i = " << i << endl;
}

void precedence()
{
    int i = 0;
    printingContent(++i); // Prints 1
    i = 0;
    printingContent(i++); // Prints 0
    cout << "________Printing numbers_____" << endl;
    vector<int> numbers(20, 2);
    for (auto it = begin(numbers); it != end(numbers); ++it)
    {
        ++*it + 20;
        *it++ += 3;
    }
    for (auto it = begin(numbers); it != end(numbers); ++it)
    {
        printingContent(*it);
    }
}

void lambda_func()
{
    int i = 2;
    // You need the i for refering to external code.
    auto a = [i](int x)
    {
        cout << i + x << endl;
    };

    a(3);
}

void lambda_square()
{
    int i = 5;
    auto createSquare = [i](int width, int height)
    {
        vector<vector<int>> v;
        for (int i = 0; i < height; i++)
        {
            vector<int> row;
            for (int j = 0; j < width; j++)
            {
                row.push_back(i);
            }
            v.push_back(row);
        }
        return v;
    };

    auto isEven = [](int x)
    {
        return (x % 2 == 0) ? true : false;
    };

    auto createIsEvenSquare = [isEven, createSquare](int width, int height)
    {
        vector<vector<int>> vectorSquare = createSquare(width, height);
        vector<vector<bool>> ans;
        for (auto row : vectorSquare)
        {
            vector<bool> ansRow;
            for (int element : row)
            {
                ansRow.push_back(isEven(element));
            }
            ans.push_back(ansRow);
        }
        return ans;
    };

    auto printSquaresData = [](vector<vector<bool>> vectorSquares)
    {
        for (auto row : vectorSquares)
        {
            for (auto element : row)
            {
                printf(" %d ", element);
            }
        }
    };

    vector<vector<bool>> square = createIsEvenSquare(4, 5);
    printSquaresData(square);
    bool b = isEven(7);

    // Multiply row and square and check if
    cout << boolalpha << b << endl;
}

void test_p4(void)
{
    vector<int> res = p4(2); // Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking value");
    loop_vect(res);
}

#include <memory>

class Foo
{
    int x;

public:
    Foo(int x) : x{x} {}
    int getX() { return x; }
    ~Foo()
    {
        cout << "~Foo" << endl;
    }
};

void test_shared(void)
{
    shared_ptr<Foo> sp(new Foo(100));
    cout << sp->getX() << endl;
    
    cout << sp.use_count() << endl;
    shared_ptr<Foo> sp1 = sp;
    cout << sp.use_count() << endl;
    cout << sp1.use_count() << endl;
}

TEST_LIST = {
    // {"askdynamic", askdynamic},
    {"test_shared", test_shared},
    // {"test_p4", test_p4},
    // {"precedence", precedence},
    // {"lambda_func", lambda_func},
    // {"lambda_square", lambda_square},
    {0}};