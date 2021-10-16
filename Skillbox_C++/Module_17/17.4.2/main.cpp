#include <iostream>

const int arrLength{10};

void ReversCopy(int number[arrLength]) {
  for (int i = 0, temp; i < arrLength/2; ++i) {
    temp = number[0 + i];
    number[0 + i] = number[arrLength - 1 - i];
    number[arrLength - 1 - i] = temp;
  }
}

void ArrayOutput(int numbers[arrLength]) {
  std::cout << "Revers array: ";
  for (int i = 0; i < arrLength; ++i) {
    std::cout << numbers[i] << " ";
  }
}

int main() {
  std::cout << "--- M17 exercise 2" << std::endl;
  int numbers[arrLength];
  std::cout << "Input 10 numbers: ";
  for (int &number: numbers) {
    std::cin >> number;
  }
  ReversCopy(numbers);
  ArrayOutput(numbers);
  return 0;
}
