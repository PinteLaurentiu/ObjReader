
#include <iostream>
#include "vector.h"
using namespace std;
int main()
{
    MathVector<int, 2> b;
    MathVector<int, 3> a = {2, 3, 4};
    MathVector<int, 5> a2 = {a, 5, 6};
    for (int i = 0; i < 5; i++) {
        cout << a2[i] << ", ";
    }
    cout << endl;
    const MathVector<int, 2>& b2 = b;
    for (int i = 0; i < 2; i++) {
        cout << b2[i] << ", ";
    }
    cout << endl;
    cout << "Hello World!!!" << endl;
    return 0;
}
