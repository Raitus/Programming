#include <iostream>
#include "vector"

void PrintDB(const std::vector<int> &dataBase, int firstElement) {
  std::cout << "Data base now: ";
  if (firstElement!=dataBase.size()) {
    for (int i = firstElement, count = 0; count!=dataBase.size(); ++i, ++count) {
      if (i==dataBase.size()) {
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
  std::vector<int> dataBase;
  std::cout << "Input data base elements:\n";
  do {
	std::cin >> number;
	if (number==-1) {
	  break;
	}
	if (i==maxElements) {
	  i = 0;
	}
	if (dataBase.size()==i) {
	  dataBase.push_back(number);
	} else {
	  dataBase[i] = number;
	}
	++i;
  } while (true);
  PrintDB(dataBase, i);
}

int main() {
  std::cout << "--- Low size data base ---\n" << std::endl;
  int maxBDElements{20};
  AddDBElements(maxBDElements);
  return 0;
}
