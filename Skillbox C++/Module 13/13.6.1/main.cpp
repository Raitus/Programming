#include <iostream>
#include "vector"

std::vector<int> DeleteVecNumbers(std::vector<int> &vec, int number) {
  for (auto i=vec.begin(); i != vec.end(); ) {
	if (*i==number){
	  i=vec.erase(i);
	}else{
	  ++i;
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
	if (vec.empty()){
	  std::cout << "No one number is keeping.";
	}else{
	  std::cout << "Keeping numbers: ";
	  for (int i : vec) {
	    std::cout << i << " ";
	  }
	}
  }
  return 0;
}
