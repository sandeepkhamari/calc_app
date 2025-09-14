#include "sqr.hpp"

double Square::area(double side) 
{
    //cout<<"square_lib::Square::area() says: "<<endl;
    return Power().power(side, 2);
}