#include <iostream>
using namespace std;
int main() {
    int t;
    float m, F, distance;
    std::cout << "- - - Космический симулятор - - -" << std::endl;
    do {
        cout << "Введите массу корабля: ";
        cin >> m;
        if (m<1)cout<<"Масса должна быть положительной!";
    }while (m<1);
    do {
        cout << "Введите силу тяги корабля (Н): ";
        cin >> F;
        if (F<1)cout<<"Сила должна быть положительной!";
    }while (F<1);
    do {
        cout << "Введите время (с): ";
        cin >> t;
        if (t<1)cout<<"Время должно быть положительным!";
    }while (t<1);

    distance = ((F/m)*(t*t))/2;
    cout<<"Корабль отлетел на "<<distance<<" м.";

    return 0;
}
