#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Rectangle{
    // private:
    public:
        double length;
        double width;
        void setlength(float len){
            this->length = len;
        }

        void setwidth(float len){
            this->width = len;
        }

        float perimeter(){
            return 2* this->width + 2* this->length;
        }
        
        float area(){
            return this->width * this-> length;
        }

        void show(){
            printf("\nThe length is %f, and width is %f\n", this->length , this->width);
        }

        int sameArea(Rectangle anotherRec){
            return this->area() == anotherRec.area();
        }
};



