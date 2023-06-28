#include "../layer/percepton.h"
#include "../layer/dense_layer.h"
#include "../include/dnn.h"

namespace activation_fn
{
    // ReLU
    FLOAT ReLU(FLOAT &x)
    {
        if (x > 0)
            return x;
        else
            return FLOAT(0);
    }

    FLOAT d_ReLU(FLOAT &x)
    {
        if (x > 0)
            return FLOAT(1);
        else
            return FLOAT(0);
    }
}

template <typename T>
class MathOperator
{
public:
    // function
    virtual T fn(T &x) = 0;
    // derivative
    virtual T d_fn(T &x) = 0;
};

template <typename T>
class ActivationOperator : public MathOperator<T>
{
public:
    string act_fn_name;

    // function to activate a percepton
    function<FLOAT(FLOAT &)> forward_fn;
    function<FLOAT(FLOAT &)> backward_fn;

    // empty constructor
    ActivationOperator<T>() {}

    // overload constructor
    ActivationOperator<T>(char *act_fn_name = RELU) : act_fn_name(act_fn_name)
    {
        if (string(act_fn_name) == string(RELU))
        {
            forward_fn = activation_fn::ReLU;
            backward_fn = activation_fn::d_ReLU;
        }
    }

    // x -> y = f(x)
    T fn(T &x) override
    {
        return forward(x);
    };

    // d(f(x))/d(x)
    T d_fn(T &x) override
    {
        return backward(x);
    };

protected:
    //  forward to calculate f(x)
    // backward to calculate d(f)/d(x)
    FLOAT forward(FLOAT &x)
    {
        return forward_fn(x);
    }
    FLOAT backward(FLOAT &x)
    {
        return backward_fn(x);
    }

    // overload forward and backward fns
    // for percepton and layer

    // percepton
    void forward(Percepton<FLOAT> &x)
    {
        x.value_new = forward(x.value_old);
    }

    // percepton
    void backward(Percepton<FLOAT> &x)
    {
        x.value_new = backward(x.value_old);
    }

    // layer
    void forward(Dense_Layer<T> &x)
    {
        for_each(x.begin(), x.end(), [](Percepton<T> &i)
                 { forward(i); });
    }
    // layer
    void backward(Dense_Layer<T> &x)
    {
        for_each(x.begin(), x.end(), [](Percepton<T> &i)
                 { backward(i); });
    }
};
