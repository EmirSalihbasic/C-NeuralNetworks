#include <iostream>
#include <vector>

// Perceptron class
class Perceptron {
public:
    Perceptron(double weight1, double weight2, double bias) : weight1(weight1), weight2(weight2), bias(bias) {}

    int predict(int input1, int input2) {
        double weightedSum = input1 * weight1 + input2 * weight2 + bias;
        return (weightedSum >= 0) ? 1 : 0;
    }

private:
    double weight1;
    double weight2;
    double bias;
};

int main() {
    // Create an OR gate perceptron
    Perceptron orGate(1, 1, -0.5);  // Weights: 1, 1; Bias: -0.5

    // Test the OR gate perceptron
    std::vector<std::pair<int, int>> testCases = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    std::cout << "OR Gate Truth Table:" << std::endl;
    for (const auto& testCase : testCases) {
        int input1 = testCase.first;
        int input2 = testCase.second;
        int result = orGate.predict(input1, input2);

        std::cout << input1 << " OR " << input2 << " = " << result << std::endl;
    }

    return 0;
}