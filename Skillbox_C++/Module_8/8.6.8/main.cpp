#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "- - - Биолаборатория 2.0 - - -" << endl;
    float dw, nNew;
    int d, w, n, nOld;
    cout << "Введите количество капель воды: ";
    cin >> w;
    cout << "Введите количество капель антибиотика: ";
    cin >> d;
    cout << "Введите количество королебактерий: ";
    cin >> n;
    nOld = n;
    dw = d / w;
    for (int i = 1; i <= 20; i++) {
        nNew = 2 * nOld - nOld * dw;
        cout << "Концентрация на " << i << "-й минуте:\n - королебактерий: \t" << abs(nNew) << " ("
             << abs(round(nNew / n * 100)) << "%)" << ";";
        if (dw == 0) {
            cout << "\n - антибиотика: \t" << dw << " (0%)" << "." << endl;
        } else {
            cout << "\n - антибиотика: \t" << dw << " (" << round(dw / (d / w) * 100) << "%)" << "." << endl;
        }
        nOld = nNew;
        dw *= 0.8;
    }
    return 0;
}
