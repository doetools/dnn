#ifndef _DENSE_LAYER_H
#define _DENSE_LAYER_H
#include "../include/dnn.h"

template <typename T>
class Dense_Layer
{

public:
    // num of perceptons
    int num_percepton = 0;

    // value
    vector<Perceptron<T>> perceptons{num_percepton, Perceptron<T>()};

    // a default constructor
    Dense_Layer() = default;
    // a parameterized constructor
    Dense_Layer(int N) : num_percepton(N) {}
};
#endif