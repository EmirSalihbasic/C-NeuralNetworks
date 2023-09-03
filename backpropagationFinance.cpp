#include <iostream>
#include <vector>
#include <cmath> //Standard library headers

class NeuralNetwork
{
public:
    NeuralNetwork(double learningRate) : learningRate(learningRate)
    {
        weightInputToHidden = 0.5;
        weightHiddenToOutput = 0.5; // this weights play crucial role here, connections between inputs and hidden layer
        biasHidden = 0.1;
        biasOutput = 0.1; // It is helping the network to make better prediction
    }

    double predict(double input)
    {
        // Forward pass
        double hidden = sigmoid(weightInputToHidden * input + biasHidden);
        double output = sigmoid(weightHiddenToOutput * hidden + biasOutput);
        return output;
    }

    void train(double input, double target)
    {
        // Forward pass
        double hidden = sigmoid(weightInputToHidden * input + biasHidden);
        double output = sigmoid(weightHiddenToOutput * hidden + biasOutput);

        // Backpropagation
        double outputError = target - output; // It calculates the error between target value and predicted output
        double outputDelta = outputError * sigmoidDerivative(output);

        double hiddenError = weightHiddenToOutput * outputDelta;
        double hiddenDelta = hiddenError * sigmoidDerivative(hidden);

        // Update weights and biases
        weightHiddenToOutput += learningRate * outputDelta * hidden;
        weightInputToHidden += learningRate * hiddenDelta * input;
        biasOutput += learningRate * outputDelta;
        biasHidden += learningRate * hiddenDelta;
    }

private:
    double learningRate;
    double weightInputToHidden;
    double weightHiddenToOutput;
    double biasHidden;
    double biasOutput;

    double sigmoid(double x)
    {
        return 1.0 / (1.0 + std::exp(-x));
    }

    double sigmoidDerivative(double x)
    {
        return x * (1.0 - x);
    }
};

int main()
{
    NeuralNetwork neuralNetwork(0.1); // Learning rate of 0.1

    // Sample training data
    std::vector<double> inputs = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> targets = {0.2, 0.4, 0.6, 0.8, 1.0};

    // Training the neural network
    for (int epoch = 0; epoch < 1000; ++epoch)
    {
        for (size_t i = 0; i < inputs.size(); ++i)
        {
            neuralNetwork.train(inputs[i], targets[i]);
        }
    }

    // Predicting using the trained network
    double inputToPredict = 0.6;
    double prediction = neuralNetwork.predict(inputToPredict);

    std::cout << "Predicted Output for Input " << inputToPredict << ": " << prediction << std::endl;

    return 0;
}
