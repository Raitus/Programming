#include <iostream>

using namespace std;

int main() {
    float lightPoint, highLight;
    int leftFrontier, rightFrontier;
    std::cout << "Градиент серого\n" << std::endl;
    cout << "Введите яркость левой границы градиента: ";
    cin >> leftFrontier;
    cout << "Введите яркость правой границы градиента: ";
    cin >> rightFrontier;
    cout << "Введите положение точек между границами от 0 до 1: ";
    cin >> lightPoint;

    float range = rightFrontier - leftFrontier;
    highLight = lightPoint * range + leftFrontier;
    cout << "Яркость искомой точки: " << highLight << ".";
    return 0;
}
