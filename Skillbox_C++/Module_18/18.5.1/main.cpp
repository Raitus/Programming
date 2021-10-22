#include <iostream>
#include <vector>

void SwapVec(std::vector<int> &vectorA, int arrayB[]) {
  std::vector<int> tempVector{vectorA};
  for (int i = 0; i < vectorA.size(); ++i) {
    vectorA[i] = *(arrayB + i);
    arrayB[i] = tempVector[i];
  }
}

void Print(std::vector<int> &vectorA, int arrayB[4]) {
  for (int i: vectorA) { std::cout << i; }
  std::cout << std::endl;
  for (int i = 0; i < vectorA.size(); ++i) {
      std::cout<< arrayB[i];
  }
}

int main() {
  std::cout << "--- M18 Exercise 1 ---" << std::endl;

  std::vector<int> a = {1, 2, 3, 4};
  int b[] = {2, 4, 6, 8};
  SwapVec(a, b);
  Print(a, b);

  return 0;
}
