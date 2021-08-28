#include <iostream>

char WinCheck(char desk[3][3]) {
  for (int step = 0, countMainDiagonal{0}; step < 3; ++step) {
	if (desk[step][step]!=' ') {
	  char symbol = desk[step][step];
	  for (int i = 0, countHorizontal = 0, countVertical = 0; i < 3; ++i) { //Horizontal & Vertical check
		if (desk[step][i]==symbol) {
		  countHorizontal++;
		  if (countHorizontal==3) {
			return symbol;
		  }
		}
		if (desk[i][step]==symbol) {
		  countVertical++;
		  if (countVertical==3) {
			return symbol;
		  }
		}
	  }
	  //Diagonals check
	  if (desk[step][step]==symbol) {
		countMainDiagonal++;
		if (countMainDiagonal==3) {
		  return symbol;
		}
	  }
	  if(step==1) {
		for (int i = 0, bump{2}, countForeignDiagonal{0}; i < 3; ++i, --bump) {
		  if (desk[i][bump]==symbol) {
			countForeignDiagonal++;
			if (countForeignDiagonal==3) {
			  return symbol;
			}
		  }
		}
	  }
	}
  }
  return ' ';
}

bool WinAnalysis(char desk[3][3]) {
  char symbol = WinCheck(desk);
  if (symbol=='X') {
	std::cout << "Player 1 won!\n";
	return true;
  } else if (symbol=='O') {
	std::cout << "Player 2 won!\n";
	return true;
  } else {
	return false;
  }
}

void MoveCheck(char desk[3][3], bool player) {
  int x, y;
  bool check;
  do {
	check = false;
	std::cout << "Input coordinates: ";
	std::cin >> y >> x;
	if (x < 1 || x > 3 || y < 1 || y > 3 || desk[x - 1][y - 1]!=' ') {
	  std::cout << "You entered wrong coordinates. Try again!\n";
	  check = true;
	}
  } while (check);
  if (player) {
	desk[x - 1][y - 1] = 'X';
  } else {
	desk[x - 1][y - 1] = 'O';
  }
}

void PlayerMove(int move, char desk[3][3]) {
  bool player;
  if (move%2==0) {
	player = true;
	std::cout << "First player move.\n";
	MoveCheck(desk, player);
  } else {
	player = false;
	std::cout << "Second player move.\n";
	MoveCheck(desk, player);
  }
}

void DeskPrint(const int x, const int y, char desk[3][3]) {
  for (int i = 0; i < y + 2; ++i) {
	if (i==0 || i==y + 1) {
	  for (int j = 0; j < x + 2; ++j) {
		std::cout << "-";
	  }
	} else {
	  for (int j = 0; j < x + 2; ++j) {
		if (j==0 || j==x + 1) {
		  std::cout << "|";
		} else {
		  std::cout << desk[i - 1][j - 1];
		}
	  }
	}
	std::cout << std::endl;
  }
}

int main() {
  std::cout << "--- Tic toe game 3x3 ---\n" << std::endl;
  char desk[3][3] = {{' ', ' ', ' '},
					 {' ', ' ', ' '},
					 {' ', ' ', ' '}};
  DeskPrint(3,
			3,
			desk); //Initially, I wanted to do it through constant variables, but there was not enough knowledge in transferring the array.
  for (int i = 0; i < 9; ++i) {
	PlayerMove(i, desk);
	DeskPrint(3, 3, desk);
	if (WinAnalysis(desk)) {
	  break;
	} else if (i==8) {
	  std::cout << "Nobody won.\n";
	}
  }
  return 0;
}
