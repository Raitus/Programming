#include <iostream>

bool CheckStringPossibility(std::string str) {
  if (str.length()==3) {
	for (char i : str) {
	  if (i=='X' || i=='O' || i=='.') {
		return true;
	  } else {
		return false;
	  }
	}
  }
	return false;
}

int main() {
  std::cout << "--- Tic-tac-toe result analysis ---" << std::endl;
  std::cout << "Input result of tic-tac-toe game: \n";
  std::string y1, y2, y3, x1, x2, x3;
  std::cin >> y1;
  std::cin >> y2;
  std::cin >> y3;
  if (CheckStringPossibility(y1) && CheckStringPossibility(y2) && CheckStringPossibility(y3)) {

  } else {
	std::cout << "Incorrect!\n";
  }
  return 0;
}
