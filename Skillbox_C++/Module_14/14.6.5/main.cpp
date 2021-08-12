#include <iostream>
#include "vector"
void InputMatrix(std::vector<std::vector<int>> &matr){
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin>>matr[i][j];
    }
  }
}

int main() {
  std::cout << "--- Diagonal matrix ---\n" << std::endl;
  std::vector<std::vector<int>> matr(4, std::vector<int>(4));

  std::cout<<"Input matrix: \n";
  InputMatrix(matr);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
	  if (i!=j){
	    matr[i][j]=0;
	  }
	  std::cout<<matr[i][j]<<" ";
	}
	std::cout<<std::endl;
  }

  return 0;
}
