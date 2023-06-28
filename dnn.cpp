#include "./layer/percepton.cpp"

int main()
{
    Percepton<FLOAT> p(RELU);
    cout << p.act_fn_name << endl;
    FLOAT x = 15;
    cout << p(x) << endl;
    cout << p.activation.d_fn(x) << endl;

    // ActivationOperator<FLOAT>(string("ReLU"));
}