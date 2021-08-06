#include <iostream>
#include "vector"

std::vector<int> add_to_position(std::vector<int> vec, int val, int position) {
  position--;
  for (int i = vec.size()-1; i >= position; --i) {
	vec[i]=vec[i-1];
  }
  vec[position]=val;
  return vec;
}

std::vector<int> NewVector(std::vector<int> vector, int vecSize) {
  int num = 0;
  do {
	vecSize++;
	std::vector<int> newVector(vecSize);
	std::cout << "Input your number: ";
	std::cin >> num;
	int pos;
	do {
	  std::cout << "Input your position: ";
	  std::cin >> pos;
	} while (pos <= 0 || pos > vecSize);

	for (int i = 0; i < vecSize - 1; ++i) {
	  newVector[i] = vector[i];
	}
	if (pos!=vecSize) {
	  vector=add_to_position(newVector, num, pos);
	} else {
	  newVector[vecSize - 1] = num;
	  vector = newVector;
	}
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
