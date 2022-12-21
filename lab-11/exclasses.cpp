#include <cstdio>
const int pi_num = 3.14;
#include <string>

using namespace std;
class Circle
{
private:
    double radius;
    string color;

public:
    Circle(double r, string c) : radius(r), color(c) {}
    double area()
    {
        return pi_num * radius * radius;
    }
    friend double circumference(Circle c);
};

double circumference(Circle c)
{
    return 2 * pi_num * c.radius;
}
