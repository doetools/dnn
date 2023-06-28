#ifndef _PERCEPTON_H
#define _PERCEPTON_H

#include "../include/dnn.h"

template <typename T>
class Percepton
{

public:
    // value after activation fn
    T value_new{0.0};

    // function before activation fn
    T value_old{0.0};
};

#endif