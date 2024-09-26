#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    double C;
    cin >> A >> B;
    C = (double)A / B;
    cout.precision(15);
    cout << C;
    return 0;
}