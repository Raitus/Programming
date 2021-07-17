#include <iostream>
#include <cmath>
using namespace std;

int main() {
    std::cout << "- - - Кенийский бегун - - -" << std::endl;
    int distance, temp, i;
    float tempAvarage = 0;
    cout << "Привет, Сэм! Сколько километров ты пробежал? - ";
    cin >> distance;
    for (i = 1; i <= distance; ++i) {
        cout << "Какой у тебя был темп на " << i << "-м километре? - ";
        cin >> temp;
        tempAvarage += temp;
    }

    tempAvarage /= distance * 60.f;
    cout << "Твой средний темп за тренировку: " << (int) tempAvarage;

    if ((int) tempAvarage % 5 == 0 || ((int) tempAvarage % 10 >= 6 && (int) tempAvarage % 10 <= 9) ||
        ((int) tempAvarage % 100 >= 11 && (int) tempAvarage % 100 <= 14)) {
        cout << " минут";
    } else if ((int) tempAvarage % 10 >= 2 && (int) tempAvarage % 10 <= 4) {
        cout << " минуты";
    } else cout << " минута";

    tempAvarage = (tempAvarage - (int) tempAvarage) * 60;
    if (tempAvarage > 0) {
        cout << " " << round(tempAvarage);

        if ((int) tempAvarage % 5 == 0 || ((int) tempAvarage % 10 >= 6 && (int) tempAvarage % 10 <= 9) ||
            ((int) tempAvarage % 100 >= 11 && (int) tempAvarage % 100 <= 14)) {
            cout << " секунд." << endl;
        } else if ((int) tempAvarage % 10 >= 2 && (int) tempAvarage % 10 <= 4) {
            cout << " секунды." << endl;
        } else cout << " секунда." << endl;
    } else cout << ".";
    return 0;
}
