#include "./layer/percepton.h"
#include "./operator/activation.cpp"
#include "./include/dnn.h"

int main()
{
    ActivationOperator<FLOAT> act = ActivationOperator<FLOAT>(RELU);
}