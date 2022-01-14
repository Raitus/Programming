#include <iostream>

int PurposeInput(){
    int num;
    std::cout<<"Input the number: ";
    bool check;
    do {
        check=false;
        std::cin>>num;
        if (num<=0){
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
  std::cout << "--- M18 Exercise 2" << std::endl;
  std::cout<<Ladder(PurposeInput())<<std::endl;
  return 0;
}
