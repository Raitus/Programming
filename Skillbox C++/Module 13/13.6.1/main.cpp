#include <iostream>
#include "vector"

std::vector<int> DeleteVecNumbers(std::vector<int> vec, int number) {
  for (int i = 0; i < vec.size(); ++i) {
	if (vec[i]==number) {
	  for (int j = i + 1; j < vec.size(); ++j) {
		vec[j - 1] = vec[j];
	  }
	  vec.pop_back();
	  --i;
	}
  }
  return vec;
}

int main() {

  int count;
  do {
    std::cout << "How many numbers do you want to enter? - ";
    std::cin >> count;
  }while(count<1);

  std::vector<int> vec(count);
  std::cout << "Input your numbers: ";
  for (int i = 0; i < count; ++i) {
	std::cin >> vec[i];
  }

  {
	int number;
	std::cout << "Which number do you want to delete from vector? - ";
	std::cin >> number;
	vec=DeleteVecNumbers(vec, number);
	if (vec.size()==0){
	  std::cout << "No one number is keeping.";
	}else{
	  std::cout << "Keeping numbers: ";
	  for (int i = 0; i < vec.size(); ++i) {
	    std::cout << vec[i] << " ";
	  }
	}
  }
  return 0;
}
