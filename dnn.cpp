#include "./include/dnn.h"

int main()
{
    // ActivationOperator<FLOAT> act = ActivationOperator<FLOAT>(RELU);
    // FLOAT x = 10;

    // cout << "activation value: " << act.fn(x) << endl;
    // cout << "derivative activation value: " << act.d_fn(x) << endl;

    // activation a layer
    Dense_Layer<FLOAT> l = Dense_Layer<FLOAT>(10);

    for_each(l.perceptons.begin(), l.perceptons.end(), [](auto &x)
             { x.value_old = 12; });

    ActivationOperator<FLOAT, Dense_Layer> act_layer{RELU};

    act_layer.d_fn(l);

    for_each(l.perceptons.begin(), l.perceptons.end(), [](auto &x)
             { cout << x.value_new << endl; });
}