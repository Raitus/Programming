#include <iostream>

int main() {
    int x = 0.001f * 1.496f * pow(10, 11), xSmall = 0, y = 0; //Расчет можно сделать в плоть до границы переменной типа float. В этой программе до 999млн.
    char key;
    std::cout << "\t- - - Красный Марс 2.0 - - -\n";
    x /= pow(10, 3);
    int i = 0;

    while (true) {
        /*for(int q=0; q<=3003;q++){          // Цикл для тестирования. (В замен бесконечного 10стр. и избавлением от cin в 27-й строке)
            if (q<1000||q>2000) { key = 'D'; }
            else {key = 'A';}*/

        if (xSmall == 0) {
            i = 0;
        }
        std::cout << "[Программа]: Марсоход находится на позиции " << x;

        if (x > 0) {
            if (xSmall < 10)std::cout << "00" << xSmall;
            else if (xSmall < 100)std::cout << "0" << xSmall;
            else std::cout << xSmall;
        } else if (x < 0) {
            if (xSmall < 10)std::cout << "00" << xSmall;
            else if (xSmall < 100)std::cout << "0" << xSmall;
            else std::cout << xSmall;
        }
        std::cout << ", " << round(y) << ", введите команду:\n[Оператор]: ";
        std::cin>>key;

        if (key == 'A') {
            xSmall -= 1;
            if (xSmall == -1) {
                i++;
                if (i == 1) {
                    xSmall = 999;
                    x -= 1;
                }
            }
        } else if (key == 'W') {
            y += 1;
        } else if (key == 'S') {
            y -= 1;
        } else if (key == 'D') {
            xSmall += 1;
            if (xSmall == 1000) {
                xSmall = 0;
                x += 1;
            }
        }
    }
}