#include <iostream>

using namespace std;

int main() {
    int longOfCharacters, middle;
    cout << "- - - Важные объявления - - -" << endl;
    do {
        cout << "Введите длину строки: ";
        cin >> longOfCharacters;
    }while (longOfCharacters<=0);
    do {
        cout << "Введите количество восклицаний: ";
        cin >> middle;
    }while (middle>longOfCharacters);

    for (int i=0;i<longOfCharacters;i++)
    if (middle%2==1 && i>((longOfCharacters/2)-(middle/2+1))&&i<((longOfCharacters/2)+(middle/2+1)) ||
    (middle%2==0 && i>((longOfCharacters/2)-(middle/2+1))&&i<((longOfCharacters/2)+(middle/2)))) cout<<"!";
    else cout<<"~";

    return 0;
}
