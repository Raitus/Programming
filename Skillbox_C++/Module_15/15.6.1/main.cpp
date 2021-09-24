#include <iostream>
#include <array>

int main() {
  std::cout << "--- Exercise 1 ---" << std::endl;
  std::array<int, 9> list = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int firstElement, finalElement, maxSum{0};
  for (int i = 0; i < list.size(); ++i) {
    int sum, firstIndex, secondIndex;
    sum = 0;
    if (list[i] > 0) {
      firstIndex = i;
      secondIndex = i;
      sum += list[i];
      for (int j = i + 1, minusCount{0}; i < list.size() - 1 && j < list.size(); ++j) {
        if (list[j] < 0) {
          minusCount += list[j];
        } else if (std::abs(minusCount) < list[j]) {
          secondIndex = j;
          sum += list[j] + minusCount;
          minusCount = 0;
        }
      }
      for (int j = i - 1, minusCount{0}; i > 0 && j > 0; --j) {
        if (list[j] < 0) {
          minusCount += list[j];
        } else if (std::abs(minusCount) < list[j]) {
          secondIndex = j;
          sum += list[j] + minusCount;
          minusCount = 0;
        }
      }
      if (maxSum < sum) {
        maxSum = sum;
        firstElement = firstIndex;
        finalElement = secondIndex;
      }
    }
  }
  std::cout << "Max sum of elements located between " << firstElement << " and " << finalElement << ".";
  return 0;
}
