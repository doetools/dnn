#include "./layer/percepton.cpp"

int main()
{
    Percepton<FLOAT> p(string("ReLU"));
    cout << p.act_fn_name << endl;
    FLOAT x = 15;
    cout << p(x) << endl;

    // ActivationOperator<FLOAT>(string("ReLU"));
}