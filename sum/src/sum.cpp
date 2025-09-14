#pragma once
#include "sum.hpp"

int Sum::summation(int n)
{
    Addition add;
    int total = 0;
    //cout<<"sum_lib::Sum::summation() says: "<<endl;
    for (int i = 1; i <= n; ++i) 
    {
        total = add.add(total, i);
    }
    return total;
}