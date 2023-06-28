#include "../include/dnn.h"
#include "../operator/activation.cpp"

template <typename T>
class Percepton
{

public:
    // value after activation fn
    T value{0.0};

    // function before activation fn
    T value_old{0.0};

    // activation fn name
    string act_fn_name{string(RELU)};

    // activation fn
    ActivationOperator<T> activation = ActivationOperator<T>(act_fn_name);

    // constructor
    Percepton<T>(string act_fn_name) : act_fn_name(act_fn_name)
    {
    }
    // overload
    Percepton<T>(char *act_fn_name) : act_fn_name(string(act_fn_name))
    {
    }

    // call activation function
    T call_act_fn(T &x = NULL)
    {
        if (x)
            value = activation.fn(x);
        else
            value = activation.fn(value_old);

        return value;
    }
    // automatic call
    T operator()(T &x)
    {
        return call_act_fn(x);
    };
};