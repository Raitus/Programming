#include <iostream>

int main() {
  std::cout << "--- Snake way ---\n" << std::endl;
  const int x{5}, y{5};
  int array[x][y];
  for (int i = 0, number = 0; i < y; ++i) {
	for (int j = 0; j < x; ++j, ++number) {
	  array[i][j] = number;
	  std::cout<<array[i][j]<<"\t";
	}
	std::cout<<std::endl;
	++i;
	for (int j = x - 1; i < y && j >= 0; --j, ++number) {
	  array[i][j] = number;
	}
	for (int j = 0; i < y && j < x; ++j) {
	  std::cout<<array[i][j]<<"\t";
	}
	std::cout<<std::endl;
  }
  return 0;
}
