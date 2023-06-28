#include "../layer/percepton.h"

namespace activation_fn
{
    // ReLU
    FLOAT ReLU(FLOAT &x) const
    {
        if (x > 0)
            return x;
        else
            return FLOAT(0);
    }

    FLOAT d_ReLU(FLOAT &x) const
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

    function<FLOAT(FLOAT)> forward;
    function<FLOAT(FLOAT)> backward;

    // overload constructors
    ActivationOperator<T>(string act_fn_name = string(RELU)) : act_fn_name(act_fn_name)
    {
        if (act_fn_name == string(RELU))
        {
            forward = ReLU;
            backward = d_ReLU;
        }
    }
    ActivationOperator<T>(char *act_fn_name = RELU) : act_fn_name(act_fn_name)
    {
        if (string(act_fn_name) == string(RELU))
        {
            forward = ReLU;
            backward = d_ReLU;
        }
    }

    // fn, will not change object
    T fn(T &x) const override
    {
        if (act_fn_name == string(RELU))
            return ReLU(x);
    };

    // derivative, will not change object
    T d_fn(T &x) const override
    {
        if (act_fn_name == string(RELU))
            return d_ReLU(x);
    };

protected:
    // overload forward and backward fns
    // for percepton and layer

    // percepton
    void forward(Percepton<FLOAT> &x) const
    {
        x.value_new = ReLU(x.old);
    }

    // percepton
    void backward(Percepton<FLOAT> &x) const
    {
        x.value_new = ReLU(x.old);
    }

    // layer
    void forward(Dense_Layer<T> &x) const
    {
        for_each(x.begin(), x.end(), [](Percepton<T> &i)
                 { ReLU(i) });
    }
    // layer
    void backward(Dense_Layer<T> &x) const
    {
        for_each(x.begin(), x.end(), [](Percepton<T> &i)
                 { d_ReLU(i) });
    }
};
