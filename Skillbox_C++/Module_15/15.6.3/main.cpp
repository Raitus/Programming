#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::cout << "--- M15 Exercise 3 ---" << std::endl;
  std::vector<int> list;
  int num;
  do {
    std::sort(list.begin(), list.end());
    if (list.size() > 4) {
      std::cout << list[4] << std::endl;
    } else {
      std::cout << "This array doesn't have even 5 elements." << std::endl;
    }
    std::cout << "Input list of numbers: ";
    bool check;
    do {
      check = false;
      std::cin >> num;
      if (num != -1 && num != -2) {
        list.push_back(num);
        check = true;
      }
    } while (check);
  } while (num != -2);
  return 0;
}
