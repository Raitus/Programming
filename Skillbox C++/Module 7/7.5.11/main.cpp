#include <iostream>

using namespace std;

int main() {
    int heightOfTriangle;
    cout << "- - - Треугольник Паскаля - - -" << endl;
    do {
        cout << "Введите высоту треугольника: ";
        cin >> heightOfTriangle;
        if (heightOfTriangle>13)cout<<"Введите число меньше или равно 13.\n";
    } while (heightOfTriangle <= 0/*||heightOfTriangle>13*/);
    for (int y = 0; y < heightOfTriangle; y++) {
        for (int x = 0; x <= heightOfTriangle  - y; x++) {
            cout << " ";
        }

        for (int x = 0; x <= y; x++) {
            int factorial = 1, result;
            for (int i = 1; i <= x; i++) {
                factorial *= i;
            }
            result = factorial;
            factorial = 1;

            for (int i = 1; i <= (y - x); i++) {
                factorial *= i;
            }
            result *= factorial;
            factorial = 1;

            for (int i = 1; i <= y; i++) {
                factorial *= i;
            }
            result = factorial / result;
            cout << result << " ";

        }
        cout << "\n";
    }
    return 0;
}
