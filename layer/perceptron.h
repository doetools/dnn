#ifndef _PERCEPTON_H
#define _PERCEPTON_H

template <typename T>
class Perceptron
{

public:
    // value after activation fn
    T value_new{0.0};

    // function before activation fn
    T value_old{0.0};

    // a default constructor
    Perceptron() = default;
};

#endif