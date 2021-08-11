#include <iostream>

int RepeatedNumber(int numbers[], int length) {
  int min{numbers[0]}, max{numbers[0]}, sum{0}, minSum{0};
  for (int i = 0; i < length; ++i) {
	sum += numbers[i];
	if (numbers[i] < min) {
	  min = numbers[i];
	}
	if (numbers[i] > max) {
	  max = numbers[i];
	}
  }
  max -= min;
  if (max!=length-1){
    return 0;
  }else{
	for (int i = 0; i <= max; ++i) {
	  minSum += i + min;
	}
	return sum - minSum;
  }
}

int main() {
  std::cout << "--- Number sequence ---\n" << std::endl;
  int numbers[15];
  int length{sizeof(numbers)/sizeof(numbers[0])};
  for (int i = 0; i < length; ++i) {
	std::cin >> numbers[i];
  }
  int result = RepeatedNumber(numbers, length);
  result==0 ? std::cout << "Numbers didn't repeat or count of repeated numbers more than 1!" : std::cout << "Repeating number is " << result;
  return 0;
}
