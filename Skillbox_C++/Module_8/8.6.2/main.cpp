#include <iostream>
#include <math.h>

using namespace std;

int main() {
    std::cout << "- - - Друзья Оушена - - -\n" << std::endl;
    int N, K;
    float Tseconds, Tminutes;
    do {
        cout << "Введите количество крутящихся ручек: ";
        cin >> N;
        if (N < 1)cout << "Количество ручек должно быть положительным!\n";
    } while (N < 1);
    do {
        cout << "Введите количество положений у ручек: ";
        cin >> K;
        if (K < 1)cout << "Количество положений у ручек должно быть положительным!\n";
    } while (K < 1);
    do {
        cout << "Введите количество времени на 1 комбинацию: ";
        cin >> Tseconds;
        if (Tseconds < 1)cout << "Время должно быть положительным!\n";
    } while (Tseconds < 1);

    Tseconds = pow(N, K) * Tseconds;

    cout << "Необходимо " << round(Tseconds) << " c.";
    if (Tseconds >= 60) {
        Tminutes = Tseconds / 60;
        Tseconds = ((float) Tminutes - (int) Tminutes) * 60;
        cout << " или "<<(int) Tminutes;
        if ((int) Tminutes % 5 == 0 || ((int) Tminutes % 10 >= 6 && (int) Tminutes % 10 <= 9) || ((int) Tminutes % 100 >= 11 && (int) Tminutes % 100 <= 14)) {
            cout << " минут";
        } else if ((int) Tminutes % 10 >= 2 && (int) Tminutes % 10 <= 4) {
            cout << " минуты";
        } else cout << " минута";

        if (Tseconds > 0) {
            cout << " и "<<(int)Tseconds ;
            if ((int)Tseconds % 5 == 0 || ((int)Tseconds % 10 >= 6 && (int) Tseconds % 10 <= 9) || ((int) Tseconds % 100 >= 11 && (int) Tseconds % 100 <= 14)) {
                cout << " секунд." << endl;
            } else if ((int) Tseconds % 10 >= 2 && (int) Tseconds % 10 <= 4) {
                cout << " секунды." << endl;
            } else cout << " секунда." << endl;
        }else cout<<".";
    }
    return 0;
}
