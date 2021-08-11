#include <iostream>

int main() {
  std::cout << "--- Snake way ---\n" << std::endl;
  const int x{5}, y{5};
  int array[x][y];
  for (int i = 0, number = 0; i < y; ++i) {
	for (int j = 0; j < x; ++j, ++number) {
	  array[i][j] = number;
	}
	++i;
	for (int j = x - 1; i < y && j >= 0; --j, ++number) {
	  array[i][j] = number;
	}
  }

  for (auto & i : array) {
	for (int j : i) {
	  std::cout << j << "\t";
	}
	std::cout << std::endl;
  }
  return 0;
}
