#include <iostream>
#include <array>

int main() {
  std::cout << "--- Exercise 1 ---" << std::endl;
  std::array<int, 9> list = {-2, 1, 3, -4, -1, 2, 1, 5, 4};
  int maxSum{list[0] + list[1] + list[2] + list[3]}, firstElement{0};
  for (int i = 1, sum{maxSum}; i < list.size() - 3; ++i) {
    sum += list[i + 3] - list[i - 1];
    if (sum > maxSum) {
      maxSum = sum;
      firstElement = i;
    }
  }
  std::cout << "Max sum of elements located between " << firstElement << " and " << firstElement + 3 << " indexes': {"
            << list[firstElement] << "," << list[firstElement + 1] << "," << list[firstElement + 2] << ","
            << list[firstElement + 3] << "}";

  return 0;
}
