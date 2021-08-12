#include <iostream>
#include "vector"

 void InputMatrix(float matr[][4]){
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin>>matr[i][j];
    }
  }
}

int main() {
  std::cout << "--- Multiplying a matrix by a vector ---" << std::endl;

  float matrix[4][4];
  std::vector<float> V(4);
  std::vector<float> R={0,0,0,0};

  InputMatrix(matrix);
  std::cout<<"Input vector:\n";
  for (int i = 0; i < 4; ++i) {
	std::cin>>V[i];
  }

  std::cout<<"Output vector R:\n";
  for (int j = 0; j < 4; ++j) {
	for (int i = 0; i < 4; ++i) {
	  R[j]+=V[i]*matrix[j][i];
	}
	std::cout<<R[j]<<' ';
  }
  return 0;
}
