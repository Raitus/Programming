#include <iostream>
#include <array>

void PrintArray(std::array<int,6> &array) {
  std::cout << "Sorted massive of numbers: ";
  for (int i : array) {
    std::cout << i << " ";
  }
}

void ShakerSort(std::array<int,6> &array) {
  bool change{true};
  for (int i = 0, rCount = 0, lCount = 0; i < array.size() && change; ++i) {
    change = false;
    for (int j = 1 + lCount; j < array.size() - rCount; ++j) {
      if (std::abs(array[j - 1]) > std::abs(array[j])) {
        change = true;
        std::swap(array[j], array[j - 1]);
        if (j==array.size() - rCount - 1) {
          rCount++;
        }
      }
    }
    if (change) {
      change = false;
      for (int j = array.size() - rCount - 1; j >= 1 + lCount; --j) {
        if (std::abs(array[j - 1]) > std::abs(array[j])) {
          change = true;
          std::swap(array[j], array[j - 1]);
          if (j==0 + lCount) {
            lCount++;
          }
        }
      }
    }
  }
  PrintArray(array);
}

int main() {
  std::cout << "--- M15 Exercise 4 ---" << std::endl;
  std::array<int,6> array{-100, -50, -5, 1, 10, 15};
  ShakerSort(array);
  return 0;
}
