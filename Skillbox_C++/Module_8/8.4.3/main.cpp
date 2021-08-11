#include <iostream>
using namespace std;
int main() {
    float heightCabine, floor;
    std::cout << "Введите высоту нахождения пола кабины: ";
    cin>>heightCabine;
    floor=heightCabine/3.975;
    floor=rintf(floor);
floor++;
    cout<<"Лифт на "<<floor<<" этаже.";
    return 0;
}
