#include "../include/dnn.h"

template <typename T>
class MathOperator
{
public:
    // function
    virtual T fn(T &x) const = 0;
    // derivative
    virtual T d_fn(T &x) const = 0;
};

template <typename T>
class ActivationOperator : public MathOperator<T>
{
public:
    string act_fn_name;

    ActivationOperator<T>() {}

    ActivationOperator<T>(string act_fn_name) : act_fn_name(act_fn_name) {}

    // fn, will not change object
    T fn(T &x) const override
    {
        if (act_fn_name == string("ReLU"))
            return ReLU(x);
    };

    // derivative, will not change object
    T d_fn(T &x) const override
    {
        if (act_fn_name == string("ReLU"))
            return d_ReLU(x);
    };

protected:
    T ReLU(T &x) const
    {
        if (x > 0)
            return x;
        else
            return T(0);
    }

    T d_ReLU(T &x) const
    {
        if (x > 0)
            return T(1);
        else
            return T(0);
    }
};
