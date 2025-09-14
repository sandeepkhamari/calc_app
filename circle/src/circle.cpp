#include "circle.hpp"
#include "mult.hpp"

double Circle::area(double radius) 
{
    Multiplication m;
    //cout<<"circle_lib::Circle::area() says: "<<endl;
    return m.multiply(m.multiply(3.14159, radius) , radius);
}