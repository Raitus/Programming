#include <iostream>
#include <cmath>
using namespace std;

int main() {
    std::cout << "- - - Компьютерное зрение - - -" << std::endl;
    float x, y, xPoint, yPoint, rx, ry, sx, sy;
    cout << "Введите местоположение фигуры: \n";
    cin >> x >> y;
    cout << "Введите местоположение точки на доске: \n";
    cin >> xPoint >> yPoint;

    x *= 10;
    y *= 10;
    xPoint*=10;
    yPoint*=10;
    cout << "Конь в клетке (" << (int) x << ", " << (int) y << "). ";
    cout << "Точка в клетке (" << (int) xPoint << ", " << (int) yPoint << ")."<<endl;
    rx = 0.05f - (((float)x-(int)x)/10.0f);
    x/=10;
    x+=rx;
    ry = 0.05f - (((float)y-(int)y)/10.0f);
    y/=10;
    y+=ry;
    sx = 0.05f - (((float)xPoint-(int)xPoint)/10.0f);
    xPoint/=10;
    xPoint+=sx;
    sy = 0.05f - (((float)yPoint-(int)yPoint)/10.0f);
    yPoint/=10;
    yPoint+=sy;

    xPoint-=x;
    yPoint-=y;

    float distance = sqrt(xPoint*xPoint + yPoint*yPoint);
    cout<<distance<<endl;

    if (round(distance*10000)/10000==0.2236f) cout<< "Да, конь может ходить в эту точку.";
    else cout<< "Нет, конь не может ходить в эту точку.";
    return 0;
}
