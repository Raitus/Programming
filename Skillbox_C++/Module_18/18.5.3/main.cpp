#include <iostream>

bool CharCheck(const char* symbols){
    for (int count{0}; symbols[count] != '\0'; ++count) {
        if (count > 10||!(symbols[count] >= '0' && symbols[count] <= '9')||symbols[count]!=' '||symbols[count]!=',') return false;
    }
    return true;
}

bool ParametersCount(const char* symbols){
    for (int i = 0; i < symbols[i] != '\0'; ++i) {
        if (i!=0 && symbols[i]>='0' && symbols[i]<=9 && symbols[i-1]==' ') return false;
    }
    return true;
}

bool StringCorrectness(const char* symbols, bool single){
    for (int i = 0; symbols[i] != '\0' ; ++i) {
        if (single){
            if (!(symbols[i] >= '0' && symbols[i] <= '9')) return false;
        }else{
            if (i == 0 && !(symbols[i] >= '0' && symbols[i] <= '9')
                || symbols[i] == ',' && !(symbols[i-1] >= '0' && symbols[i-1] <= '9')
                || symbols[i] != ' ' && symbols[i-1] == ','
                || symbols[i-1] == ' ' && !(symbols[i] >= '0' && symbols[i] <= '9')) return false;
        }
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

int NumberInput(){
    char num[100];
    bool check, secondNum{false}, stringSingle;
    do {
        check=false;
        std::cin >> num;
        stringSingle = ParametersCount(num);
        if (!CharCheck(num)||!StringCorrectness(num, stringSingle)){
            check = true;
            std::cout<< "You inputted wrong number! Try again: ";
        }
    }while(check);
    return CharToInt(num);
}

int Ladder(int step, int maxJumpHigh=3){
    if (step == 0){
        return 0;
    }else if (step == 1){
        return 1;
    }
    return (Ladder(step-2)+Ladder(step-1)+1);
}

int main() {
    std::cout << "--- M18 Exercise 3 ---" << std::endl;
    std::cout << Ladder(NumberInput()) << std::endl;
    return 0;
}
