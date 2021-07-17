#include <iostream>
using namespace std;
int main() {
    float cost, wight, result, sale;
    std::cout << "Орехи" << std::endl;
    cout<< "Введите цену товара за 100г: ";
    cin>>cost;
    cout<< "Итоговый вес покупки: ";
    cin>> wight;
    cout<< "Скидка в %: ";
    cin>> sale;

    result = ((wight/100)*cost)-(((wight/100)*cost)*(sale/100));
    cout<<result;
    return 0;
}
