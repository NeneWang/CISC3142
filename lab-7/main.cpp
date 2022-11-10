#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Rectangle
{
    // private:
public:
    double length;
    double width;

    // sets length of the figure
    void setlength(float len)
    {
        this->length = len;
    }

    // sets width of the rectangle
    void setwidth(float len)
    {
        this->width = len;
    }

    // retruns perimeter of the figure
    float perimeter()
    {
        return 2 * this->width + 2 * this->length;
    }

    // returns area of the figure
    float area()
    {
        return this->width * this->length;
    }

    // Prints The length and width of the figure
    void show()
    {
        printf("\nThe length is %f, and width is %f\n", this->length, this->width);
    }

    int sameArea(Rectangle anotherRec)
    {
        return this->area() == anotherRec.area();
    }
};


// TODO: Unit Test this.
class Sample
{
private:
    int x;
    double y;

public:
    Sample();            // Constructor 1
    Sample(int);         // Constructor 2
    Sample(int, int);    // Constructor 3
    Sample(int, double); // Constructor 4

    Sample(){
        this->x = 1;
        this->y = 0;
    }
    Sample(int x){
        this->x = x;
        this->y = 0;
    }

    Sample(int x, int y){
        this->x = x;
        this->y = y;
    }

    Sample(int x, double y){
        this->x = x;
        this->y = y;
    }

    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }

};




void printTwoRectangleStats(Rectangle rec1, Rectangle rec2);

void P1_subproblem2()
{
    Rectangle rec1;
    rec1.setlength(5);
    rec1.setwidth(2.5);

    Rectangle rec2;
    rec2.setlength(5);
    rec2.setwidth(18.9);
    printTwoRectangleStats(rec1, rec2);
}

void P1_subproblem3()
{
    Rectangle rec1;
    rec1.setlength(15);
    rec1.setwidth(6.3);

    Rectangle rec2;
    rec2.setlength(5);
    rec2.setwidth(18.9);

    printTwoRectangleStats(rec1, rec2);

    printf("Rectangle 1 and 2 have the same area: %s.\n", rec1.sameArea(rec2) ? "True" : "False");
}

void printTwoRectangleStats(Rectangle rec1, Rectangle rec2)
{

    cout << "\n\nRectangle 1:";
    rec1.show();
    cout << "Area is: " << rec1.area() << endl;

    cout << "\nRectangle 2:";
    rec2.show();
    cout << "Area is: " << rec2.area() << endl;
}




