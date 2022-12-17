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
// https://www.youtube.com/watch?v=-dREJCf2ve4
class Foo
{
public:
    int x;

    Foo(int x) : x{x} {}
    int getX() { return x; }
    ~Foo()
    {
        // When finished.
        cout << "~Foo" << endl;
    }
};

void test_shared(void)
{
    shared_ptr<Foo> sp(new Foo(100));
    cout << sp->x << endl;
    cout << (*sp).x << endl;
    cout << sp->getX() << endl;
    cout << "Is unique: " << sp.unique() << endl;
    cout << sp.use_count() << endl;

    shared_ptr<Foo> sp1 = sp;
    cout << "Is unique: " << sp.unique() << endl;
    cout << sp1->x << endl;
    cout << sp.use_count() << endl;
    cout << sp1.use_count() << endl;

    sp1->x += 1;
    cout << (*sp).x << endl;
}

void managing_memory_directly(void)
{
    // https://youtu.be/DuJxoTzrCLY
    int *pi = new int(1024);          // object to which pi points has value 1024
    string *ps = new string(10, '9'); // *ps is "9999999999"
    // vector with ten elements with values from 0 to 9
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    float *stuff = new float();
    cout << stuff << '\n';
    cout << *stuff << '\n';

    *stuff = 10.f;

    cout << *stuff << '\n';

    delete stuff;

    int *p(new int(42)); // p points to dynamic memory
    auto q = p;          // p and q point to the same memory
    cout << q << " " << p << endl;
    cout << *q << " " << *p << endl;

    delete p; // invalidates both p and q
    cout << "address" << endl;
    cout << q << " " << p << endl;
    cout << "values" << endl;
    cout << *q << " " << *p << endl;
    p = nullptr; // indicates that p is no longer bound to an object
    // stuff = nullptr;
    cout << "After indiicating is no longer bound" << endl;
    cout << q << " " << p << endl;
    // The foollowing will cause an error.
    cout << *q << " " << *p << endl;
}

void normalcase(void)
{
    float f1 = 2.0f;
    float &f2 = f1;
    float f3 = f1;

    f1 = 3;
    cout << f2 << endl;
    cout << f3 << endl;
}

void managedFoo(void)
{
    Foo *pi = new Foo(23);
    pi->getX();
}

void nonManagedFoo(void)
{
    Foo pi = Foo(23);
    pi.getX();
}

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

void templateExample(void)
{
    cout << myMax<int>(3, 7) << endl; // Call myMax for int
    cout << myMax<double>(3.0, 7.0)
         << endl; // call myMax for double
    cout << myMax<char>('g', 'e')
         << endl; // call myMax for char
}

TEST_LIST = {
    // {"askdynamic", askdynamic},
    // {"test_shared", test_shared},
    // {"managing_memory_directly", managing_memory_directly},
    // {"normalcase", normalcase},
    {"managedFoo", managedFoo},
    {"nonManagedFoo", nonManagedFoo},
    // {"test_p4", test_p4},
    // {"precedence", precedence},
    // {"lambda_func", lambda_func},
    // {"lambda_square", lambda_square},
    {0}};