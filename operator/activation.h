#ifndef _ACTIVATION_H
#define _ACTIVATION_H

#include "../include/dnn.h"

namespace activation_fn
{

    // ReLU
    template <typename T>
    FLOAT ReLU(FLOAT &x)
    {
        FLOAT y = 0;

        if (x > 0)
            y = x;

        return y;
    }
    template <typename T>
    FLOAT d_ReLU(FLOAT &x)
    {
        FLOAT dy = 0;

        if (x > 0)
            dy = FLOAT(1);

        return dy;
    }
}

template <typename T, template <typename> class C>
class MathOperator
{
public:
    // function
    virtual C<T> fn(C<T> &x) = 0;
    // derivative
    virtual C<T> d_fn(C<T> &x) = 0;

    // a default constructor
    MathOperator() = default;
};

template <typename T, template <typename> class C>
class ActivationOperator : public MathOperator<T, C>
{
public:
    string act_fn_name;

    // function to activate a percepton
    function<T(T &)> forward_fn;
    function<T(T &)> backward_fn;

    // a default constructor
    ActivationOperator<T, C>() = default;

    // overload constructor
    ActivationOperator<T, C>(char *act_fn_name = RELU) : act_fn_name(act_fn_name)
    {
        if (string(act_fn_name) == string(RELU))
        {
            forward_fn = activation_fn::ReLU<T>;
            backward_fn = activation_fn::d_ReLU<T>;
        }
    }

    // x -> y = f(x)
    C<T> fn(C<T> &x) override
    {
        return forward(x);
    };

    // d(f(x))/d(x)
    C<T> d_fn(C<T> &x) override
    {
        return backward(x);
    };

protected:
    //  forward to calculate f(x)
    // backward to calculate d(f)/d(x)
    T forward(T &x)
    {
        return forward_fn(x);
    }
    T backward(T &x)
    {
        return backward_fn(x);
    }

    // overload forward and backward fns
    // for percepton and layer

    // percepton
    Perceptron<T> forward(Perceptron<T> &x)
    {
        x.value_new = forward(x.value_old);
        return x;
    }

    // percepton
    Perceptron<T> backward(Perceptron<T> &x)
    {
        x.value_new = backward(x.value_old);
        return x;
    }

    // layer
    Dense_Layer<T> forward(Dense_Layer<T> &x)
    {
        for_each(x.perceptons.begin(), x.perceptons.end(), [&](Perceptron<T> &i)
                 { this->forward(i); });
        return x;
    }
    // layer
    Dense_Layer<T> backward(Dense_Layer<T> &x)
    {
        for_each(x.perceptons.begin(), x.perceptons.end(), [&](Perceptron<T> &i)
                 { this->backward(i); });

        return x;
    }
};

#endif