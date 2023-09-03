#include <iostream>
#include <cmath>

double sigmoid(double x)
{
    return 1.0 / (1.0 + std::exp(-x)); // This is mathematical formula for the sigmoid function
} // std::exp(-x)  is c++ version of mathematical  e^(-x)

int main()
{
    // Given values
    double a = 1;
    double b = 2;
    double c = 1;

    // My formula
    double x = sigmoid(a * b + c);

    std::cout << "x = " << x << std::endl;

    return 0;
}