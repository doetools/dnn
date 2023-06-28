#ifndef _DENSE_LAYER_H
#define _DENSE_LAYER_H
#include "../include/dnn.h"
#include "percepton.h"

template <typename T>
class Dense_Layer
{

public:
    // num of perceptons
    int num_percepton = 0;

    // value after activation fn
    vector<Percepton<T>> value_new = vector<Percepton<T>>(num_percepton, Percepton<T>());

    // function before activation fn
    vector<Percepton<T>> value_old = vector<Percepton<T>>(num_percepton, Percepton<T>());

    // constructor
    Dense_Layer(int N) : num_percepton(N) {}
};
#endif