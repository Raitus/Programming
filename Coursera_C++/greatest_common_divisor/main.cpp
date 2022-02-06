#include <iostream>

int main() {
    int num1, num2, greatestDivisor{0};
    std::cin>>num1>>num2;
    while( num1>0 && num2>0 ) {
        if (num1>num2){
            num1%=num2;
            if (num1!=0) greatestDivisor=num1;
            else if (num2!=0) {
                greatestDivisor=num2;
                break;
            }
        }else if (num1<num2) {
            num2%=num1;
            if (num2!=0) greatestDivisor=num2;
            else if (num1!=0) {
                greatestDivisor=num1;
                break;
            }
        }else{
            greatestDivisor=num2;
            break;
        }
    }
    std::cout << greatestDivisor;
    /*if (num1>0 && num2>0) {
        if (num1 % 2 == 0) {
            divisor = 2;
        }
        do {
            if (num1 % divisor == 0 && num2 % divisor == 0) {
                greatestDivisor = divisor;
            }
            divisor += 2;
        } while (divisor <= num1 && divisor <= num2);
        std::cout << greatestDivisor;
    } else {
        std::cout<<0;
    }*/
    return 0;
}
