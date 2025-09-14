#include "pow.hpp"

// Power function using repeated multiplication
double Power::power(double base, int exponent) 
{
    //cout << "pow_lib::Power::power() says: " << endl;
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) 
    {
        result = Multiplication().multiply(result, base);
    }
    return result;
}