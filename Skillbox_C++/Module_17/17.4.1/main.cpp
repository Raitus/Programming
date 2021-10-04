#include <iostream>

void swap(int *variable1, int *variable2){
  int variableTemp=*variable1;
  *variable1=*variable2;
  *variable2=variableTemp;
}

int main() {
  std::cout << "--- M17 Exercise 1 ---" << std::endl;
  int a = 10;
  int b = 20;
  swap(&a, &b);
  std::cout << a << " " << b; // 20 10
  return 0;
}
