#include <iostream>
#include "array"

void InputMatrix(std::array<std::array <int,4>,4> matrix){
  for (int i = 0; i < 4; ++i) {
	for (int j = 0; j < 4; ++j) {
	  std::cin>>matrix[i][j];
	}
  }
}

int main() {
  std::cout << "--- Equality of matrixes ---\n" << std::endl;
  std::array<std::array <int,4>,4> A{};
  std::array<std::array <int,4>,4> B{};

  std::cout<<"Input first matrix: \n";
  InputMatrix(A);
  std::cout<<"Input second matrix: \n";
  InputMatrix(B);

  std::cout << (A==B ? "Matrixes are equivalent!" : "Matrixes aren`t equivalent!");
  
  return 0;
}
