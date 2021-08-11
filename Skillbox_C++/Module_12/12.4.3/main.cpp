#include <iostream>

void PrintArray(float number[], int length) {
  std::cout << "Sorted massive of numbers: ";
  for (int i = 0; i < length; ++i) {
	std::cout << number[i] << " ";
  }
}

void ShakerSort(float *numbers, int length) {
  bool change{true};
  for (int i = 0, rCount = 0, lCount = 0; i < length && change; ++i) {
	change = false;
	for (int j = 1 + lCount; j < length - rCount; ++j) {
	  if (numbers[j - 1] < numbers[j]) {
		change = true;
		std::swap(numbers[j], numbers[j - 1]);
		if (j==length - rCount - 1) {
		  rCount++;
		}
	  }
	}
	if (change) {
	  change = false;
	  for (int j = length - rCount - 1; j >= 1 + lCount; --j) {
		if (numbers[j - 1] < numbers[j]) {
		  change = true;
		  std::swap(numbers[j], numbers[j - 1]);
		  if (j==0 + lCount) {
			lCount++;
		  }
		}
	  }
	}
  }
  PrintArray(numbers, length);
}

void BubbleSort(float numbers[], int length) {
  bool change{true};
  for (int i = 0; i < length && change; ++i) {
	change = false;
	for (int j = 1; j < length - i; ++j) {
	  if (numbers[j - 1] < numbers[j]) {
		change = true;
		std::swap(numbers[j], numbers[j - 1]);
	  }
	}
  }
  PrintArray(numbers, length);
}

bool Choose() {
  int i;
  std::cout << "Choose way of sorting:\n 1. Bubble sort;\n 2. Shaker sort.\n";
  do {
	std::cout << "Input number: ";
	std::cin >> i;
	if (i!=1 && i!=2)std::cout << "Incorrect!\n";
  } while (i!=1 && i!=2);

  if (i==1)return true;
  else return false;
}

int main() {
  std::cout << "\t--- Bubble sort ---\n" << std::endl;
  float numbers[15]; //= {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
  int length{sizeof(numbers)/sizeof(numbers[0])};
  std::cout << "Input 15 fractional numbers: ";
  for (int i = 0; i < length; ++i) {
	std::cin >> numbers[i];
  }

  if (Choose()) BubbleSort(numbers, length);
  else ShakerSort(numbers, length);
  return 0;
}
