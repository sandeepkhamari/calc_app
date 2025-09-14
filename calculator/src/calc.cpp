#include "calc.hpp"
#include <iostream>

void start_calculator()
{
    cout << "Please choose an operation to perform:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Area of Circle" << endl;
    cout << "6. Power" << endl;
    cout << "7. Area of Square" << endl;
    cout << "8. Summation of first N natural numbers" << endl;
    cout << "Enter your choice (1-8): ";
    int choice;
    cin >> choice;
    switch (choice) 
    {
        case 1: 
        {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            Addition addition;
            cout << "Result: " << addition.add(a, b) << endl;
            break;
        }
        case 2: 
        {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            Subtraction subtraction;
            cout << "Result: " << subtraction.subtract(a, b) << endl;
            break;
        }
        case 3: 
        {
            double a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            Multiplication multiplication;
            cout << "Result: " << multiplication.multiply(a, b) << endl;
            break;
        }
        case 4: 
        {
            double a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            Division division;
            cout << "Result: " << division.divide(a, b) << endl;
            break;
        }
        case 5: 
        {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            Circle circle;
            cout << "Area of Circle: " << circle.area(radius) << endl;
            break;
        }
        case 6: 
        {
            double base;
            int exponent;
            cout << "Enter base and exponent (integer): ";
            cin >> base >> exponent;
            Power power;
            cout << "Result: " << power.power(base, exponent) << endl;
            break;
        }
        case 7: 
        {
            double side;
            cout << "Enter the side length of the square: ";
            cin >> side;
            Square square;
            cout << "Area of Square: " << square.area(side) << endl;
            break;
        }
        case 8: 
        {
            int n;
            cout << "Enter a positive integer N: ";
            cin >> n;
            Sum sum;
            cout << "Summation of first " << n << " natural numbers is: " << sum.summation(n) << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
}