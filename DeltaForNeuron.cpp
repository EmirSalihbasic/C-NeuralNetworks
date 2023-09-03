#include <iostream>
#include <cmath>

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double sigmoidDerivative(double x) {    //derivative of sigmoid activation function
    return x * (1.0 - x);
}

int main() {
    // Given inputs
    double predictedOutput = 0.75;
    double target = 0.9;

    // Calculate the error
    double outputError = predictedOutput - target;

    // Calculate delta
    double delta = outputError * sigmoidDerivative(predictedOutput);  //The delta is then calculated using the error and the derivative of the sigmoid function.

    // Print the calculated delta
    std::cout << "Delta for the neuron: " << delta << std::endl;

    return 0;
}

/*  Mathematically
Predicted Output: predictedOutput = 0.75
Target Output: target = 0.9
Error Calculation:

outputError = predictedOutput - target = 0.75 - 0.9 = -0.15
Backpropagation:

Calculate delta:
delta = outputError * sigmoidDerivative(predictedOutput)
delta = -0.15 * (0.75 * (1 - 0.75))
delta = -0.15 * 0.1875
delta = -0.028125
*/