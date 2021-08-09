#include <iostream>
#include "vector"

void PrintDB(std::vector<int> dataBase, int maxElements, int firstElement, bool full) {
  std::cout << "Data base now: ";
  if (full) {
    for (int i = firstElement, count = 0; count!=maxElements; ++i, ++count) {
      if (i==maxElements) {
		i = 0;
	  }
	  std::cout << dataBase[i] << " ";
	}
  } else {
	for (int i = 0; i!=firstElement; ++i) {
	  std::cout << dataBase[i] << " ";
	}
  }

}

void AddDBElements(int maxElements) {
  int number, i{0};
  bool full{false};
  std::vector<int> dataBase;
  std::cout << "Input data base elements:\n";
  do {
	std::cin >> number;
	if (number==-1) {
	  break;
	}
	if (i==maxElements) {
	  i = 0;
	  full = true;
	}
	if (!full) {
	  dataBase.push_back(number);
	} else {
	  dataBase[i] = number;
	}
	++i;
  } while (true);
  PrintDB(dataBase, maxElements, i, full);
}

int main() {
  std::cout << "--- Low size data base ---\n" << std::endl;
  std::vector<int> dataBase;
  int maxBDElements{20};
  AddDBElements(maxBDElements);
  return 0;
}
