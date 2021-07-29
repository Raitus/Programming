#include <iostream>

int RepeatedNumber(int numbers[], int length) {
  for (int i = 0; i < length; ++i) {
	int temp = numbers[i];
	for (int j = 1 + i; j < length; ++j) {
	  if (numbers[j]==temp) {
		return temp;
	  }
	}
  }
  return 0;
}

int main() {
  std::cout << "--- Number sequence ---\n" << std::endl;
  int numbers[15];
  int length{sizeof(numbers)/sizeof(numbers[0])};
  for (int i = 0; i < length; ++i) {
	std::cin >> numbers[i];
  }
  int result = RepeatedNumber(numbers, length);
  result==0 ? std::cout << "Numbers didn't repeat!" : std::cout << "Repeating number is " << result;
  return 0;
}
