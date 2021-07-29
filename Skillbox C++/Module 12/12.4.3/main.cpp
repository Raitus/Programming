#include <iostream>

void PrintArray(float number[], int length) {
  std::cout<<"Sorted massive of numbers: ";
  for (int i = 0; i < length; ++i) {
	std::cout<<number[i]<<" ";
  }
}

void BubbleSort(float numbers[], int length) {
  bool change{true};
  for (int i = 0; i < length && change; ++i) {
	change = false;
	for (int j = 1; j < length - i; ++j) {
	  if (numbers[j-1] < numbers[j]) {
		change = true;
		std::swap(numbers[j],numbers[j-1]);
	  }
	}
  }
  PrintArray(numbers, length);
}

int main() {
  std::cout << "\t--- Bubble sort ---\n" << std::endl;
  float numbers[15]; //= {0.5, 14.2, 12.4, 5.2, 5.12, 2.8, 2.6, 2.5, 1.5, 1.25, 1.2, 1.2, 1.11, 1.1, 1.0};
  int length{sizeof(numbers)/sizeof(numbers[0])};
  std::cout<<"Input 15 fractional numbers: ";
  for (int i = 0; i < length; ++i) {
	std::cin >> numbers[i];
  }
  BubbleSort(numbers, length);
  return 0;
}
