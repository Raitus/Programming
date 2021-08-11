#include <iostream>

using namespace std;

int main() {
    cout << "\t- - - Маятник - - -" << endl;
    float amplitude, endAmplitude;
    int i;
    do {
        cout << "Введите конечную амплитуду движения маятника (в сантиметрах): ";
        cin >> endAmplitude;
    } while (endAmplitude <= 0);
    do {
        cout << "А так-же начальную амплитуду (в сантиметрах): ";
        cin >> amplitude;
    } while (amplitude < endAmplitude);


    for (i = 0; amplitude >= endAmplitude; ++i) {
        amplitude -= amplitude * 0.084;
    }
    cout << "Маятник качнулся " << i;
    if (i % 10 == 1 || (i % 10 >= 5 && i % 10 <= 9) || ((i % 100 >= 12 && i % 100 <= 14)))cout << " раз." << endl;
    else {
        cout << " раза." << endl;
    }

    return 0;
}
