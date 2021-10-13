#include <iostream>

void ReversCopy(int number[10]){
  for (int i = 0, temp; i < 5; ++i) {
    temp=number[0+i];
    number[0+i]=number[9-i];
    number[9-i]=temp;
  }
}

void ArrayOutput(int numbers[10]){
  std::cout<<"Revers array: ";
  for (int i = 0; i < 10; ++i) {
    std::cout<<numbers[i]<<" ";
  }
}

int main() {
  std::cout << "--- M17 exercise 2" << std::endl;
  int numbers[10];
  std::cout<<"Input 10 numbers: ";
  for (int & number : numbers) {
    std::cin>>number;
  }
  ReversCopy(numbers);
  ArrayOutput(numbers);
  return 0;
}
