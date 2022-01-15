#include <iostream>

bool CharCheck(const char* symbols){
    for (int count{0}; symbols[count] != '\0'; ++count) {
        if (symbols[0]=='-'||count > 10||!(symbols[count] >= '0' && symbols[count] <= '9')) return false;
    }
    return true;
}

int PurposeInput(){
    char num[100];
    std::cout<<"Input the number: ";
    bool check;
    do {
        check=false;
        std::cin>>num;
        if (!CharCheck(num)){
            check = true;
            std::cout<< "You inputted wrong number! Try again: ";
        }
    }while(check);
    return num;
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
    std::cout << "--- M18 Exercise 3" << std::endl;
    std::cout<<Ladder(PurposeInput())<<std::endl;
    return 0;
}
