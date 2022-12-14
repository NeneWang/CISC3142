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
        ++*it = 20;
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
    auto createSquare = [](int width, int height)
    {
        vector<vector<int>> v;
        for (int i = 0; i < height; i++)
        {
            vector<int> row;
            for (int j = 0; j < width; j++)
            {
                cout << i * j << " ";
                row.push_back(i * j);
            }
            cout << endl;
            v.push_back(row);
        }
        return v;
    };

    auto isEven = [](int x)
    {
        return (x % 2 == 0) ? true : false;
    };

    auto createIsEvenSquare = [isEven, createSquare](int height, int width)
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

    const int height = 4, width = 5;
    cout << endl;
    vector<vector<bool>> square = createIsEvenSquare(height, width);
    printSquaresData(square);
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
    cout << myMax<double>(3.2, 7.4)
         << endl; // call myMax for double
    cout << myMax<char>('g', 'e')
         << endl; // call myMax for char
}

#include <iterator>
#include <map>
void multimapExample(void)
{
    multimap<int, int> gquiz1; // empty multimap container

    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(6, 10));
    gquiz1.insert(pair<int, int>(6, 15));
    gquiz1.insert(pair<int, int>(6, 125));

    multimap<int, int>::iterator itr;
    cout << "\nThe multimap gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
    for (auto itr = gquiz1.find(6); itr != gquiz1.end(); itr++)
        cout << itr->first
             << '\t' << itr->second << '\n';

    // Gettin using key
    auto range = gquiz1.equal_range(6);
    for (auto it = range.first; it != range.second; it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

#include <set>

void multisetExample(void)
{
    multiset<int, greater<int>> gquiz1;

    // insert elements in random order
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    gquiz1.insert(50);
    gquiz1.insert(10);

    cout << "\nThe multiset gquiz1 is : \n";
    for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // Creating a set, in which they are oredered

    multiset<int> gquiz2(gquiz1.begin(), gquiz1.end());
    multiset<int> gquiz3(gquiz1.begin(), gquiz1.end());

    // print all elements of the multiset gquiz2
    cout << "\nThe multiset gquiz2 \n"
            "after assign from gquiz1 is : \n";
    for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // print all elements of the multiset gquiz2
    cout << "\nThe multiset gquiz3 \n"
            "after assign from gquiz1 is : \n";
    for (auto itr = gquiz3.begin(); itr != gquiz3.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // cout << "Erasing all elements up to element with value 30 in gquiz2"

    // cout << "Erasing all elements up to element with value 30 in gquiz2"
    gquiz3.erase(gquiz3.begin(), gquiz3.find(30));
    cout << "\nThe multiset gquiz3 \n"
            "aAfter removing before 30 is: \n";
    for (auto itr = gquiz3.begin(); itr != gquiz3.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // counting

    cout << "50 appears: " << gquiz3.count(50) << " times" << endl;
    cout << "gquiz3 has " << gquiz3.size() << " values" << endl;
    gquiz3.clear();
    cout << "gquiz3 has " << gquiz3.size() << " values" << endl;
    cout << "\ngquiz1.lower_bound(40) : \n"
         << *gquiz1.lower_bound(40) << endl;
    cout << "gquiz1.upper_bound(40) : \n"
         << *gquiz1.upper_bound(40) << endl;

    // lower bound and upper bound for multiset gquiz2
    cout << "gquiz2.lower_bound(40) : \n"
         << *gquiz2.lower_bound(40) << endl;

    cout << "gquiz2.lower_bound(35) : \n"
         << *gquiz2.lower_bound(35) << endl;

    cout << "gquiz2.lower_bound(45) : \n"
         << *gquiz2.lower_bound(45) << endl;

    cout << "gquiz2.upper_bound(45) : \n"
         << *gquiz2.upper_bound(45) << endl;

    cout << "gquiz2.upper_bound(40) : \n"
         << *gquiz2.upper_bound(40) << endl;
}

// void mapExample(void)

void setExample(void)
{
    set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    a.insert('A');
    a.insert('Z');
    a.erase('F');
    for (auto &str : a)
    {
        cout << str << ' ';
    }
    cout << '\n';
}

void mapExample(void)
{
    map<char, int> first;

    // initializing
    first['a'] = 10;
    first['c'] = 30;
    first['d'] = 40;
    first['b'] = 20;
    first.erase('c');

    map<char, int>::iterator it;
    cout << endl;
    for (it = first.begin(); it != first.end(); ++it)
    {
        cout << it->first << " => " << it->second << '\n';
    }

    first['b'] += 12;
    cout << first['a'] << endl; // Prints 10
    cout << first['b'] << endl;
}

#include <unordered_map>
void mapUnorderedexample(void)
{
    unordered_map<char, int> unordered;
    unordered['a'] = 10;
    unordered['c'] = 30;
    unordered['d'] = 40;
    unordered['b'] = 20;
    unordered.erase('a');

    unordered_map<char, int>::iterator it;
    cout << endl;
    for (it = unordered.begin(); it != unordered.end(); ++it)
    {
        cout << it->first << " => " << it->second << '\n';
    }

    unordered['b'] += 12;
    cout << unordered['a'] << endl; // Prints 10
    cout << unordered['b'] << endl;
}

#include <string>
void stringConversions(void)
{
    string int_str = "203";
    int int_res = stoi(int_str);

    string float_str = "203.23";
    float float_res = stof(float_str);

    string double_str = "2.12341";
    double double_res = stod(double_str);

    cout << endl;
    printf("%d - %.2f - %.3f\n", int_res + 10, float_res + 2, double_res + 1);

    int someinteger = 23;
    string formattedInteger = to_string(someinteger);
    printf("string formatted is: %s \n", formattedInteger.c_str());
    printf("number: %s\n", "12");
    printf("Pointer %p\n", &float_res);
    cout << &float_res << endl;
}

void stringParsing(void)
{
    string str_to_substr = "Hello Mister";
    cout << endl;
    printf("\nFormatting: %s", str_to_substr.c_str());
    printf("\nFormatted with first 3 characters %s", str_to_substr.substr(0, 3).c_str());
    printf("\nLast 3 characters: %s", str_to_substr.substr(str_to_substr.size() - 3).c_str());
    printf("\nCharacter in third position %c", str_to_substr[2]);
    printf("\nfinding first e in the string at: %d", str_to_substr.find('e'));
}

void switchEnumsExample(void)
{
    cout << endl;
    enum Color
    {
        red,
        green,
        blue
    };

    Color colorEnum = green;

    switch (colorEnum)
    {
    case red:
        cout << "red\n";
        break;
    case green:
        cout << "green\n";
    case blue:
        cout << "blue\n";
        break;
    default:
        cout << "No color was selected" << endl;
    }
}

void gotoStatement(void)
{
    float num, average, sum = 0.0;
    int i, n;

    cout << "\nMaximum number of inputs: ";
    cin >> n;

    for (i = 1; i <= n; ++i)
    {
        cout << "Enter n" << i << ": ";
        cin >> num;

        if (num < 0.0)
        {
            goto jump;
        }
        sum += num;
    }

jump:
    average = sum / (i - 1);
    cout << "\nAverage = " << average;
}

void tryCatchError(void)
{
    try
    {
        int age = 15;
        if (age >= 18)
        {
            cout << "Access granted - you are old enough.";
        }
        else
        {
            throw(age);
        }
    }
    catch (int myNum)
    {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum;
    }
}

#include "exclasses.cpp"

void friendExercises(void)
{
    /**
     * Create a class called "Circle" with private member variables for the radius and color.
     * Create a public function called "area" that returns the area of the circle.
     * Create a friend function called "circumference" that takes a Circle object as an argument
     * and returns the circumference of the circle.
     */
    Circle c(2.0, "red");
    cout << "Circle c has circumference " << circumference(c) << endl;
}

void dynamicPointerEx(void)
{
    // Create a dynamic pointer to an integer and assign it the value of 10.
    int *int_ptr = new int;
    *int_ptr = 10;

    // Create a dynamic pointer to a character and assign it the value 'A'.
    char *c = new char;
    *c = 'A';

    // Create a dynamic pointer to a structure and assign it values for its members.
    struct Person
    {
        string name;
        int age;
    };

    Person *p = new Person;
    p->age = 23;
    p->name = "Nelson";

    // Create a dynamic array of integers using a dynamic pointer and initialize it with a set of values.
    int *arrIntegers = new int[5];
    arrIntegers[0] = 1;
    arrIntegers[1] = 1;

    // Create a function that takes a dynamic pointer as an argument and modifies the value pointed to by the pointer.
    auto modifyValue = [](int *ptr)
    {
        *ptr = 10;
    };

    auto printPointerValue = [](int *ptr)
    {
        cout << "\nPointer value is: " << *ptr << endl;
    };

    int *new_val = new int(1);
    printPointerValue(new_val);
    modifyValue(new_val);
    printPointerValue(new_val);

    // Dealocate that value in memory
    delete (new_val);
    printPointerValue(new_val);
}

void sharedPointerEx(void)
{
    // Write a function that takes a shared pointer as an argument and increments the value pointed to by the pointer. Call this function with a shared pointer to an integer.
    auto incrementValue = [](shared_ptr<int> ptr)
    {
        (*ptr)++;
    };

    auto showSharedPointer = [](shared_ptr<int> ptr)
    {
        printf("\nShared pointer %p value: %d", ptr, *ptr);
    };

    auto showPointer = [](int *ptr)
    {
        printf("\nShared pointer %p value: %d", ptr, *ptr);
    };

    shared_ptr<int>
    pointer(new int(5));
    showSharedPointer(pointer);
    incrementValue(pointer);
    showSharedPointer(pointer);
    cout << endl;
    int *pointSample = new int(1);
    showPointer(pointSample);
    (*pointSample)++; // If the () are removed then it will modify the pointer first
    showPointer(pointSample);

    // Write a function that takes a shared pointer as an argument and returns a new shared pointer to a different data type. Call this function with a shared pointer to an integer and print the value of the returned shared pointer.

    // Write a program that creates a shared pointer to an integer and assigns it to a shared pointer to a const integer. Print the value of the shared pointer to a const integer.

    // Write a program that creates a shared pointer to an integer and assigns it to a shared pointer to a volatile integer. Print the value of the shared pointer to a volatile integer.

    // Write a program that creates a shared pointer to an integer and assigns it to a shared pointer to a const volatile integer. Print the value of the shared pointer to a const volatile integer.
}

void ioclassesEx()
{
    cout << "hi!" << endl;     // writes hi and a newline, then flushes the buffer
    cout << "flush!" << flush; // writes hi, then flushes the buffer; adds no data
    cout << "ends!" << ends;   // writes hi and a null, then flushes the buffer
}

auto val(int &i) { return i + i; }
auto val(float i) { return i * 10; }

void precedence_from_exam()
{
    vector<int> vec(10, 1);
    for (int &i : vec)
        int x = val(i += 2);
    auto it = vec.begin();
    while (it != vec.end())
    {
        *it = val((float)*it++);
        it++;
    }
    cout << vec[0] << " " << vec[9] << endl;

    for (auto iter : vec)
    {
        cout << iter << endl;
    }
}

#include <algorithm>
#include <numeric>
void algoEx(void)
{
    vector<int> vec0{
        3,
        8,
        4,
        1,
        2,
        4,
        5,
        7,
        6,
    };

    sort(vec0.begin(), vec0.end());
    cout
        << "defualt behavior of sort is ascending:" << endl;

    cout << "\n\n";
    loop_vect(vec0);
    sort(vec0.begin(), vec0.end(), [](int x, int y)
         { return x > y; });
    cout << "by passing a boolean lambda function as a fourth parameter we define a different comparison" << endl;
    loop_vect(vec0);

    int x = accumulate(vec0.begin(), vec0.end(), 100);

    cout << "accumulate yeilds: " << x << endl;

    int m = accumulate(vec0.begin(), vec0.end(), 1, [](int x, int y)
                       { return x * y; });

    cout << "accumulate with lambda multiplication" << m << endl;
}

void containerOperations(void){
    
}

TEST_LIST = {
    // {"askdynamic", askdynamic},
    // {"test_shared", test_shared},
    // {"managing_memory_directly", managing_memory_directly},
    // {"normalcase", normalcase},
    // {"managedFoo", managedFoo},
    // {"nonManagedFoo", nonManagedFoo},
    // {"templateExample", templateExample},
    // {"multimapExample", multimapExample},
    // {"multisetExample", multisetExample},
    // {"test_p4", test_p4},
    // {"precedence", precedence},
    // {"lambda_func", lambda_func},
    // {"lambda_square", lambda_square},
    // {"precedence", precedence},
    // {"precedence_from_exam", precedence_from_exam},
    // {"setExample", setExample},
    // {"mapExample", mapExample},
    // {"mapUnorderedexample", mapUnorderedexample},
    // {"stringConversions", stringConversions},
    // {"stringParsing", stringParsing},
    // {"switchEnumsExample", switchEnumsExample},
    // {"gotoStatement", gotoStatement},
    // {"tryCatchError", tryCatchError},
    // {"friendExercises", friendExercises},
    // {"dynamicPointerEx", dynamicPointerEx},
    // {"sharedPointerEx", sharedPointerEx},
    // {"ioclassesEx", ioclassesEx},
    {"algoEx", algoEx},
    {0}};