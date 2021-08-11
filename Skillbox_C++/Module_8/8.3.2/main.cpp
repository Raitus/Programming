#include <iostream>

using namespace std;

int main() {
    std::cout << "- - - Компьютерное зрение - - -" << std::endl;
    float x, y, rx, ry;
    cout << "Введите местоположение фигуры: \n";
    cin >> x >> y;

    x *= 10;
    y *= 10;
    cout << "Фигура находится в клетке (" << (int) x << ", " << (int) y << ")."<<endl;

    rx = 0.05f - (((float)x-(int)x)/10.0f);
    ry = 0.05f - (((float)y-(int)y)/10.0f);

    cout << "Поправьте положение фигуры на (" << rx << ", " << ry << ").";
    return 0;
}
