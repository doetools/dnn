#ifndef _ADD_H
#define _ADD_H

#include "../include/dnn.h"

template <class T>
T operator+(const T &x, const T &y)
{
    T out(x.size(), 0);

    for (auto i = 0; i < x.size(); i++)
    {
        out[i] = x[i] + y[i];
    }

    return out;
}
#endif