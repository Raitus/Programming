#include <iostream>

int Factorial(int num){
    if (num>1) {
        return num*Factorial(num-1);
    }else return 1;
}

int main() {
    int num;
    std::cin>>num;
    std::cout<<Factorial(num)<<std::endl;
    return 0;
}
