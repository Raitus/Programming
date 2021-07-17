#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "\t- - - Убийца Steam - - -\n" << endl;
    int fileSize, internetSpeed, downloaded = 0, i;
    do {
        cout << "Укажите размер файла для скачивания: ";
        cin >> fileSize;
        if (fileSize<1)cout<<"Исходя из ответа, Вам ничего не нужно скачивать!\n";
    }while (fileSize<1);
    do {
        cout << "Укажите скорость вашего соединения: ";
        cin >> internetSpeed;
        if (internetSpeed<1)cout<<"Загрузка не удалась. Проверьте интернет соединение!\n";
    }while (internetSpeed<1);

    for (i = 1; fileSize != downloaded; i++) {
        downloaded += internetSpeed;
        if (downloaded > fileSize)downloaded = fileSize;
        cout << "За " << i << " сек. Скачано " << downloaded << " из " << fileSize << " Мб ("
             << roundf((float) downloaded / (float) fileSize * 100.f) << "%)." << endl;
    }
    cout << "Всего затрачено " << i - 1 << " сек.";
    return 0;
}
