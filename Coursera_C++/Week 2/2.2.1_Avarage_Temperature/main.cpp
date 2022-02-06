#include <iostream>
#include <vector>

int AvarageAritmeticTemperature(const std::vector<int>& temperature){
    int allTemperatures{0};
    for (int i : temperature) {
        allTemperatures+=i;
    }
    allTemperatures/=temperature.size();
    return allTemperatures;
}

void PrintAvarageTemperature(const std::vector<int>& temperature, int avgTmp){
    std::vector<int> badDays;
    for (int i = 0; i < temperature.size(); ++i) {
        if (temperature[i]>avgTmp){
            badDays.push_back(i);
        }
    }
    std::cout<<badDays.size()<<std::endl;
    for (int badDay : badDays) {
        std::cout<<badDay<<" ";
    }
}

int main() {
    int countOfDays;
    std::cin>>countOfDays;
    std::vector<int> vec(countOfDays);
    for (int i = 0; i < countOfDays; ++i) {
        std::cin>>vec[i];
    }
    PrintAvarageTemperature(vec, AvarageAritmeticTemperature(vec));
    return 0;
}
