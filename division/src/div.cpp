#include "div.hpp"

double Division::divide(double a, double b) 
{
    if (b == 0) 
    {
        cerr << "Error: Division by zero!" << endl;
        return 0; // or handle error as appropriate
    }
    //cout << "div_lib::Division::divide() says: " << endl;
    return a / b;
}