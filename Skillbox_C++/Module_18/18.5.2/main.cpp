#include <iostream>

bool CharCheck(const char* symbols){
    for (int count{0}; symbols[count] != '\0'; ++count) {
        if (count > 10||!(symbols[count] >= '0' && symbols[count] <= '9')) return false;
    }
    return true;
}

int CharToInt(const char* symbols){
    int length{0};
    while(symbols[length] != '\0'){
        ++length;
    }
    int number{0};
    for (int numericRank{1}, num = length - 1; num >= 0; num--, numericRank*=10) {
        number+=(symbols[num]-'0')*numericRank;
    }
    return number;
}

int PurposeInput(){
    char num[100];
    bool check;
    do {
        check=false;
        std::cin >> num;
        if (!CharCheck(num)){
            check = true;
            std::cout<< "You inputted wrong number! Try again: ";
        }
    }while(check);
    return CharToInt(num);
}

int Ladder(int step){
    if (step == 0){
        return 0;
    }else if (step == 1){
        return 1;
    }
    return (Ladder(step-2)+Ladder(step-1)+1);
}

int main() {
  std::cout << "--- M18 Exercise 2" << std::endl;
  std::cout<<Ladder(PurposeInput())<<std::endl;
  return 0;
}
