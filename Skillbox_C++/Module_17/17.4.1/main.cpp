#include <iostream>

void swap(int *numA, int *numB){
  int tempNum = *numA;
  *numA=*numB;
  *numB=tempNum;
}

int main() {
  std::cout << "--- M17 Exercise 1" << std::endl;
  int a = 10;
  int b = 20;
  swap(&a, &b);
  std::cout << a << " " << b;
  return 0;
}
