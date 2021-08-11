#include <iostream>
#include "vector"

std::vector<int> NewVector(std::vector<int> vector, int vecSize) {
  int num = 0;
  do {
	vecSize++;
	std::vector<int> newVector(vecSize);
	std::cout << "Input your number: ";
	std::cin >> num;

	for (int i = 0; i < vecSize - 1; ++i) {
	  newVector[i] = vector[i];
	}
	newVector[vecSize - 1] = num;
	vector = newVector;

  } while (num!=-1);
  return vector;
}

int main() {
  std::cout << "--- Robots queue ---\n" << std::endl;

  std::vector<int> vec = {15, 5, 6, 235, 45};
  vec = NewVector(vec, vec.size());
  std::cout << "New vector: ";
  for (int i = 0; i < vec.size(); ++i) {
	std::cout << vec[i] << " ";
  }
  return 0;
}
