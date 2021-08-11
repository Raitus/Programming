#include <iostream>
#include "vector"

int main() {
  int number;
  std::vector<int> vec;
  do {
	std::cout << "Input your number: ";
	std::cin >> number;
    vec.push_back(number);
  } while (number!=-1);
  for (int i = 0; i < vec.size(); ++i) {
	std::cout<<vec[i]<<" ";
  }

  return 0;
}
