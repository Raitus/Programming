#include <iostream>
using namespace std;
int main() {
    std::cout << "- - -Обменник на планете Плюк - - -" << std::endl;
    int chatls, gravicapa;
    float KC;
    cout<<"Введите количество чатлов для обмена: ";
    cin>>chatls;
    KC=(float)chatls/2200.0f;
    gravicapa=KC*2;
    cout<<"Количество КЦ: "<<KC<<endl;
    cout<<"или гравицап: "<<gravicapa<<endl;

    return 0;
}
