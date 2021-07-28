#include <iostream>

char Symbol(int x, int y, std::string str) {
  if (y==1) {
	return str[x-1];
  } else if (y==2) {
	return str[2 + x];
  } else if (y==3) {
	return str[5 + x];
  }
}

int ResultCheck(std::string str) {
  {
	int xCount = 0, oCount = 0;
	for (int i = 0; i < str.length(); i++) {
	  if (str[i]=='X') {
		xCount++;
	  } else if (str[i]=='O') {
		oCount++;
	  }
	}
	if (xCount < oCount) {
	  return 0;
	}

	int xWinCount = 0, oWinCount = 0;
	if (Symbol(1, 1, str)=='X' && Symbol(1, 2, str)=='X' && Symbol(1, 3, str)=='X')xWinCount++;
	if (Symbol(2, 1, str)=='X' && Symbol(2, 2, str)=='X' && Symbol(2, 3, str)=='X')xWinCount++;
	if (Symbol(3, 1, str)=='X' && Symbol(3, 2, str)=='X' && Symbol(3, 3, str)=='X')xWinCount++;
	if (Symbol(1, 1, str)=='X' && Symbol(2, 2, str)=='X' && Symbol(3, 3, str)=='X')xWinCount++;
	if (Symbol(3, 1, str)=='X' && Symbol(2, 2, str)=='X' && Symbol(1, 3, str)=='X')xWinCount++;
	if (Symbol(1, 1, str)=='X' && Symbol(2, 1, str)=='X' && Symbol(3, 1, str)=='X')xWinCount++;
	if (Symbol(1, 2, str)=='X' && Symbol(2, 2, str)=='X' && Symbol(3, 2, str)=='X')xWinCount++;
	if (Symbol(1, 3, str)=='X' && Symbol(2, 3, str)=='X' && Symbol(3, 3, str)=='X')xWinCount++;

	if (xWinCount==1 && oCount==xCount - 1) return 1;

	if (Symbol(1, 1, str)=='O' && Symbol(1, 2, str)=='O' && Symbol(1, 3, str)=='O')oWinCount++;
	if (Symbol(2, 1, str)=='O' && Symbol(2, 2, str)=='O' && Symbol(2, 3, str)=='O')oWinCount++;
	if (Symbol(3, 1, str)=='O' && Symbol(3, 2, str)=='O' && Symbol(3, 3, str)=='O')oWinCount++;
	if (Symbol(1, 1, str)=='O' && Symbol(2, 2, str)=='O' && Symbol(3, 3, str)=='O')oWinCount++;
	if (Symbol(3, 1, str)=='O' && Symbol(2, 2, str)=='O' && Symbol(1, 3, str)=='O')oWinCount++;
	if (Symbol(1, 1, str)=='O' && Symbol(2, 1, str)=='O' && Symbol(3, 1, str)=='O')oWinCount++;
	if (Symbol(1, 2, str)=='O' && Symbol(2, 2, str)=='O' && Symbol(3, 2, str)=='O')oWinCount++;
	if (Symbol(1, 3, str)=='O' && Symbol(2, 3, str)=='O' && Symbol(3, 3, str)=='O')oWinCount++;

	if (oWinCount==1 && oCount==xCount) return 2;
	else if (xWinCount==0 && oWinCount==0) return 3;
	else return 0;

  }
}

bool StringValidation(std::string str) {
  if (str.length()==9) {
	for (char i : str) {
	  if (i=='X' || i=='O' || i=='.') {

	  } else {
		return false;
	  }
	}
	return true;
  }
  return false;
}

int main() {
  std::cout << "--- Tic-tac-toe result analysis ---\n" << std::endl;
  std::cout << "Input result of tic-tac-toe game: \n";
  std::string x1, x2, x3;
  std::cin >> x1;
  std::cin >> x2;
  std::cin >> x3;
  x1 += x2 + x3;
  if (StringValidation(x1)) {
	int result = ResultCheck(x1);
	if (result==1) {
	  std::cout << "Petya won!\n";
	} else if (result==2) {
	  std::cout << "Vanya won!\n";
	} else if (result==3) {
	  std::cout << "Nobody!\n";
	} else {
	  std::cout << "Incorrect!\n";
	}
  } else {
	std::cout << "Incorrect!\n";
  }
  return 0;
}
