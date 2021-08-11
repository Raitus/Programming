#include <iostream>
#include "vector"

int main() {
  std::cout << "Input count of numbers: ";
  int count;
  std::cin >> count;

  std::cout << "Input vector numbers: ";
  std::vector<int> numbers(count);
  for (int i = 0; i < count; ++i) {
	std::cout << "Input vector numbers: ";
	std::cin >> numbers[i];
  }

  int sum = 0;
  for (int i = 0; i < count; ++i) {
	sum += numbers[i];
  }
  std::cout << "Average arithmetic number is " << sum/count;
  return 0;
}
