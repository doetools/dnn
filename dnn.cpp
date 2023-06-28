#include "./layer/percepton.h"
#include "./operator/add.cpp"

int main()
{
    vector<int> a(11, 1);
    vector<int> b(11, 10);

    vector<int> c = a + b;

    for (auto i : c)
        cout << i << endl;
}