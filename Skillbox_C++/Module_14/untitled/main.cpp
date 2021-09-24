#include <iostream>
#include "algorithm"
#include <array>

int main() {
  std::cout << "--- Snake way ---\n" << std::endl;
  const int x{5}, y{5};
  int array[x][y];

  for (int i = 0, j=0, number = 0; number < y*x; ++i, ++j, ++number) {
    //;
    array[i%x][j/x]=number;

    //std::for_each(array[0][j/x%2], array[4][j/x%2*3], std::swap);
    std::cout<<array[i%x][j/x]<<" ";
    //std::cout<<j/x%2*3;
  }
  std::ranges::reverse(array);
  //std::reverse(std::rbegin(array), std::rend(array));
  std::cout<<std::endl;
  for (int i = 0, j=0, number = 0; number < y*x; ++i, ++j, ++number) {
    //;

    //std::for_each(array[0][j/x%2], array[4][j/x%2*3], std::swap);
    std::cout<<array[i%x][j/x]<<" ";
    //std::cout<<j/x%2*3;
  }
  return 0;
}
