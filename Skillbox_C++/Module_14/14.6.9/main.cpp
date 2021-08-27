#include <iostream>
#include "array"
#include "vector"

const int fieldSize{10};

bool CoordinatesChecking(std::array<std::array<bool, fieldSize>, fieldSize> &field,
						 int &x1,
						 int &y1,
						 int &x2,
						 int &y2) {
  if (x1==x2) {
	if (y1 < y2) {
	  for (int y = y1; y <= y2; ++y) {
		if (field[y][x1]) return false;
	  }
	} else {
	  for (int y = y2; y <= y1; ++y) {
		if (field[y][x1]) return false;
	  }
	}
  } else {
	if (x1 < x2) {
	  for (int x = x1; x <= x2; ++x) {
		if (field[y1][x]) return false;
	  }
	} else {
	  for (int x = x2; x <= x1; ++x) {
		if (field[y1][x]) return false;
	  }
	}
  }
  return true;
}

void Coordinates(int &x, int &y) {
  bool checkCoordinates;
  do {
	checkCoordinates = false;
	std::cin >> x >> y;
	if (x < 0 || x > 9 || y < 0 || y > 9) {
	  checkCoordinates = true;
	  std::cout << "Incorrect coordinates. Try again!\n";
	}
  } while (checkCoordinates);
}

void Visualisation(std::array<std::array<bool, fieldSize>, fieldSize> &field) {
  std::cout << "Your field: \n";
  for (int y = 0; y < fieldSize + 1; ++y) {
	for (int x = 0; x < fieldSize + 1; ++x) {
	  if (y==0 && x==0) std::cout << "  ";
	  else if (y==0) std::cout << x - 1 << " ";
	  else if (x==0)std::cout << y - 1 << " ";
	  else std::cout << field[y - 1][x - 1] << " ";
	}
	std::cout << std::endl;
  }
  std::cout << std::endl;
}

void CoordinatesInput(std::array<std::array<bool, fieldSize>, fieldSize> &field,
					  std::vector<int> &xCoordinates,
					  std::vector<int> &yCoordinates,
					  std::string &playerName,
					  int &shipSize) {
  int x1, y1, x2, y2;
  bool correctness;
  std::cout << playerName << " input coordinates: ";
  do {
	correctness = true;
	Coordinates(x1, y1);
	Coordinates(x2, y2);
	if (((x1==x2 && std::abs(y1 - y2) + 1==shipSize) || (y1==y2 && std::abs(x1 - x2) + 1==shipSize))
		&& CoordinatesChecking(field, x1, y1, x2, y2)) {}
	else {
	  correctness = false;
	  std::cout << "Invalid ship`s coordinate! Try again.\n";
	}
  } while (!correctness);
  xCoordinates.push_back(x1);
  xCoordinates.push_back(x2);
  yCoordinates.push_back(y1);
  yCoordinates.push_back(y2);
  if (x1==x2) {
	if (y1 < y2) {
	  for (int y = y1; y <= y2; ++y) {
		field[y][x1] = true;
	  }
	} else {
	  for (int y = y2; y <= y1; ++y) {
		field[y][x1] = true;
	  }
	}
  } else {
	if (x1 < x2) {
	  for (int x = x1; x <= x2; ++x) {
		field[y1][x] = true;
	  }
	} else {
	  for (int x = x2; x <= x1; ++x) {
		field[y1][x] = true;
	  }
	}
  }
}

void FieldCreation(std::array<std::array<bool, fieldSize>, fieldSize> &field,
				   std::vector<int> &xCoordinates,
				   std::vector<int> &yCoordinates,
				   std::string &playerName) {
  int shipSize, ship1 = 4, ship2 = 3, ship3 = 2;
  bool ship4 = true;
  for (int shipCount = 10; shipCount > 0; --shipCount) {
	bool check;
	Visualisation(field);
	std::cout << "Ships left:\n * one size - " << ship1 << ";\n * two size - " << ship2 << ";\n * three size - "
			  << ship3 << ";\n * four size - " << ship4 << "\n";
	do {
	  check = false;
	  do {
		std::cout << playerName
				  << " choose the size of the ship, which do you want to place on the board (from 1 to 4): ";
		std::cin >> shipSize;
	  } while (shipSize < 1 || shipSize > 4);
	  if (shipSize==1 && ship1!=0) {
		ship1--;

		int x, y;
		std::cout << playerName << " input coordinates: ";
		Coordinates(x, y);
		xCoordinates.push_back(x);
		xCoordinates.push_back(x);
		yCoordinates.push_back(y);
		yCoordinates.push_back(y);
		field[y][x] = true;

	  } else if (shipSize==2 && ship2!=0) {
		ship2--;
		CoordinatesInput(field, xCoordinates, yCoordinates, playerName, shipSize);
	  } else if (shipSize==3 && ship3!=0) {
		ship3--;
		CoordinatesInput(field, xCoordinates, yCoordinates, playerName, shipSize);
	  } else if (shipSize==4 && ship4) {
		ship4 = false;
		CoordinatesInput(field, xCoordinates, yCoordinates, playerName, shipSize);
	  } else {
		check = true;
		std::cout << "All ships with this size on the board.\n";
	  }
	} while (check);

  }
}

void ShipDefeatingCheck(std::array<std::array<bool, fieldSize>, fieldSize> &opponentField,
						std::vector<int> &xCoordinates,
						std::vector<int> &yCoordinates,
						int &shipCount) {
  for (int i = 0; i < shipCount*2; i += 2) {
	if (!opponentField[yCoordinates[i]][xCoordinates[i]] && CoordinatesChecking(opponentField,
																				xCoordinates[i],
																				yCoordinates[i],
																				xCoordinates[i + 1],
																				yCoordinates[i + 1])) {
	  for (int j = i + 2; j < shipCount*2; ++j) {
		yCoordinates[j - 2] = yCoordinates[j];
		xCoordinates[j - 2] = xCoordinates[j];
	  }
	  shipCount--;
	}
  }
}

void Game(std::array<std::array<bool, fieldSize>, fieldSize> &attackingField,
		  std::array<std::array<bool, fieldSize>, fieldSize> &opponentField,
		  std::vector<int> &xCoordinates,
		  std::vector<int> &yCoordinates,
		  int &shipCount) {
  int x, y;
  bool check;
  do {
	check = false;
	Visualisation(attackingField);
	do {
	  std::cout << "Input coordinates of attack: ";
	  Coordinates(x, y);
	  if (attackingField[y][x])std::cout << "Wrong coordinates of attack. Try again!\n";
	} while (attackingField[y][x]);
	attackingField[y][x] = true;
	if (attackingField[y][x]==opponentField[y][x]) {
	  std::cout << "Hit!" << std::endl;
	  opponentField[y][x] = false;
	  check = true;
	  ShipDefeatingCheck(opponentField, xCoordinates, yCoordinates, shipCount);
	}
  } while (check && shipCount!=0);
  if (shipCount!=0) std::cout << "Past!" << std::endl;
}

int main() {
  std::cout << "--- Sea battle ---" << std::endl;
  std::array<std::array<bool, fieldSize>, fieldSize> field1{};
  std::array<std::array<bool, fieldSize>, fieldSize> field1Attacking{};
  std::array<std::array<bool, fieldSize>, fieldSize> field2{};
  std::array<std::array<bool, fieldSize>, fieldSize> field2Attacking{};
  std::vector<int> xCoordinatesField1, xCoordinatesField2,
	  yCoordinatesField1, yCoordinatesField2;

  field1.fill({false, false, false, false, false,
			   false, false, false, false, false});
  field2.fill({false, false, false, false, false,
			   false, false, false, false, false});
  field1Attacking.fill({false, false, false, false, false,
						false, false, false, false, false});
  field2Attacking.fill({false, false, false, false, false,
						false, false, false, false, false});

  std::string player1{"Player_1"}, player2{"Player_2"};

  std::cout << player1 << ", choose places for your ships.\n";
  FieldCreation(field1, xCoordinatesField1, yCoordinatesField1, player1);
  std::cout << player2 << ", choose places for your ships.\n";
  FieldCreation(field2, xCoordinatesField2, yCoordinatesField2, player2);

  int shipCountPlayer1 = 10, shipCountPlayer2 = 10;
  bool move{false};
  do {
	if (!move) {
	  std::cout << "\n===================" << std::endl << player1 << ", your move." << std::endl;
	  Game(field1Attacking, field2, xCoordinatesField2, yCoordinatesField2, shipCountPlayer2);
	  //ShipDefeatingCheck(field2, xCoordinatesField2, yCoordinatesField2, shipCountPlayer2);
	} else {
	  std::cout << "\n===================" << std::endl << player2 << ", your move." << std::endl;
	  Game(field2Attacking, field1, xCoordinatesField1, yCoordinatesField1, shipCountPlayer1);
	  //ShipDefeatingCheck(field1, xCoordinatesField1, yCoordinatesField1, shipCountPlayer1);
	}
	move = !move;
  } while (shipCountPlayer1!=0 && shipCountPlayer2!=0);
  if (shipCountPlayer1==0)std::cout << player2 << " won!\n";
  else std::cout << player1 << " won!\n";

  return 0;
}
