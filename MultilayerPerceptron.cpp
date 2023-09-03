#include <iostream>
#include <vector>
#include <cmath>

// Activation function: sigmoid
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// MLP class
class MultilayerPerceptron {
public:
    MultilayerPerceptron(int inputSize, int hiddenSize, int outputSize)
        : inputSize(inputSize), hiddenSize(hiddenSize), outputSize(outputSize) {
        
        weightsInputToHidden.resize(inputSize, std::vector<double>(hiddenSize, 0.5));
        weightsHiddenToOutput.resize(hiddenSize, std::vector<double>(outputSize, 0.5));
        biasHidden.resize(hiddenSize, 0.1);
        biasOutput.resize(outputSize, 0.1);
    }

    // Forward pass
    std::vector<double> predict(const std::vector<double>& input) {
        // Input to hidden layer
        std::vector<double> hidden(hiddenSize, 0.0);
        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < inputSize; ++j) {
                hidden[i] += input[j] * weightsInputToHidden[j][i];
            }
            hidden[i] += biasHidden[i];
            hidden[i] = sigmoid(hidden[i]);
        }

        // Hidden to output layer
        std::vector<double> output(outputSize, 0.0);
        for (int i = 0; i < outputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                output[i] += hidden[j] * weightsHiddenToOutput[j][i];
            }
            output[i] += biasOutput[i];
            output[i] = sigmoid(output[i]);
        }

        return output;
    }

private:
    int inputSize;
    int hiddenSize;
    int outputSize;
    std::vector<std::vector<double>> weightsInputToHidden;
    std::vector<std::vector<double>> weightsHiddenToOutput;
    std::vector<double> biasHidden;
    std::vector<double> biasOutput;
};

int main() {
    // Create a simple MLP with 2 input neurons, 2 hidden neurons, and 1 output neuron
    MultilayerPerceptron mlp(2, 2, 1);

    // Input example
    std::vector<double> input = {0.1, 0.2};

    // Make a prediction
    std::vector<double> prediction = mlp.predict(input);

    // Print the prediction
    std::cout << "Prediction: " << prediction[0] << std::endl;

    return 0;
}