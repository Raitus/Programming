#include <iostream>
#include <array>
#include <algorithm>

bool FindElements(std::array<int, 5> &list, int resNum, int &firstNum, int &secondNum) {
  for (int i = 0; i < list.size() - 1 && list[i] < resNum; ++i) {
    for (int j = i + 1; j < list.size() && list[j] < resNum; ++j) {
      if (list[i] + list[j] == resNum) {
        firstNum = list[i];
        secondNum = list[j];
        return true;
      }
    }
  }
  return false;
}

int main() {
  std::cout << "--- M15 Exercise 2 ---" << std::endl;
  std::array<int, 5> list{2, 1, 11, 7, 15};
  int resNum, firstNum, secondNum;
  std::cout << "Input result number: ";
  std::cin >> resNum;
  std::sort(list.begin(), list.end());
  if (FindElements(list, resNum, firstNum, secondNum)) {
    std::cout << "The sum of numbers " << firstNum << " and " << secondNum << " give us the result " << resNum << "."
              << std::endl;
  } else {
    std::cout << "This array doesn't have numbers to give us result " << resNum << "." << std::endl;
  }
  return 0;
}
