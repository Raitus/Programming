#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b;
    cout << "- - - Тяжело в учении, легко в бою" << endl;
    cout<<"Введите 2 числа для получения наибольшего из них: ";
    cin>>a>>b;
    cout<<"Наибольшее из указанных чисел: "<<fmaxf(a,b);
    return 0;
}
