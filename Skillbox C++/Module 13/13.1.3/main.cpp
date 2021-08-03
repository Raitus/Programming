#include <iostream>
#include "vector"

int main() {
  std::cout << "Input count of numbers: ";
  int count;
  std::cin >> count;

  std::cout << "Input vector numbers: ";
  std::vector<int> numbers(count);
  for (int i = 0; i < count; ++i) {
    std::cin >> numbers[i];
  }

  int max = numbers[0], sMax=0;
  for (int i = 0; i < count; ++i) {
	if (sMax<numbers[i]){
	  if (numbers[i]>max){
	    sMax=max;
	    max=numbers[i];
	  }else{
	    sMax=numbers[i];
	  }
	}

  }
  std::cout << "The second biggest number is " << sMax;
  return 0;
}
