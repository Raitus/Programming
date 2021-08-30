#include <iostream>
#include "array"

const int fieldSize{10};

bool BorderChecking(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                    int x1,
                    int y1,
                    int x2,
                    int y2) {
  if (x1 == x2) {
    if (y1 < y2) {
      if (y1 > 0)y1--;
      if (y2 < 9)y2++;
      if (x1 > 0)x1--;
      if (x2 < 9)x2++;
      for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
          if (field[y][x]) return false;
        }
      }
    } else {
      if (y2 > 0)y2--;
      if (y1 < 9)y1++;
      if (x2 > 0)x2--;
      if (x1 < 9)x1++;
      for (int y = y2; y <= y1; ++y) {
        for (int x = x2; x <= x1; ++x) {
          if (field[y][x]) return false;
        }
      }
    }
  } else {
    if (x1 < x2) {
      if (y1 > 0)y1--;
      if (y2 < 9)y2++;
      if (x1 > 0)x1--;
      if (x2 < 9)x2++;
      for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
          if (field[y][x]) return false;
        }
      }
    } else {
      if (y2 > 0)y2--;
      if (y1 < 9)y1++;
      if (x2 > 0)x2--;
      if (x1 < 9)x1++;
      for (int x = x2; x <= x1; ++x) {
        for (int y = y2; y <= y1; ++y) {
          if (field[y][x]) return false;
        }
      }
    }
  }
  return true;
}

void CoordinatesInput(int &x, int &y) {
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
      if (y == 0 && x == 0) std::cout << "  ";
      else if (y == 0) std::cout << x - 1 << " ";
      else if (x == 0)std::cout << y - 1 << " ";
      else std::cout << field[y - 1][x - 1] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void ShipArrangement(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                     std::string &playerName,
                     int &shipSize) {
  int x1, y1, x2, y2;
  bool correctness;
  std::cout << playerName << " input coordinates: ";
  do {
    correctness = true;
    CoordinatesInput(x1, y1);
    CoordinatesInput(x2, y2);
    if (((x1 == x2 && std::abs(y1 - y2) + 1 == shipSize) || (y1 == y2 && std::abs(x1 - x2) + 1 == shipSize))
        && BorderChecking(field, x1, y1, x2, y2)) {}
    else {
      correctness = false;
      std::cout << "Invalid ship`s coordinate! Try again.\n";
    }
  } while (!correctness);
  if (x1 == x2) {
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
      if (shipSize == 1 && ship1 != 0) {
        ship1--;

        int x, y;
        bool bordersMistake;
        std::cout << playerName << " input coordinates: ";
        do {
          bordersMistake = false;
          CoordinatesInput(x, y);
          if (!BorderChecking(field, x, y, x, y)) {
            bordersMistake = true;
          }
        } while (bordersMistake);
        field[y][x] = true;

      } else if (shipSize == 2 && ship2 != 0) {
        ship2--;
        ShipArrangement(field, playerName, shipSize);
      } else if (shipSize == 3 && ship3 != 0) {
        ship3--;
        ShipArrangement(field, playerName, shipSize);
      } else if (shipSize == 4 && ship4) {
        ship4 = false;
        ShipArrangement(field, playerName, shipSize);
      } else {
        check = true;
        std::cout << "All ships with this size on the board.\n";
      }
    } while (check);
  }
}

void Game(std::array<std::array<bool, fieldSize>, fieldSize> &attackingField,
          std::array<std::array<bool, fieldSize>, fieldSize> &opponentField,
          int &deckCount) {
  int x, y;
  bool check;
  do {
    check = false;
    Visualisation(attackingField);
    do {
      std::cout << "Input coordinates of attack: ";
      CoordinatesInput(x, y);
      if (attackingField[y][x])std::cout << "Wrong coordinates of attack. Try again!\n";
    } while (attackingField[y][x]);
    attackingField[y][x] = true;

    if (opponentField[y][x]) {
      std::cout << " - Hit!\n" << std::endl;
      opponentField[y][x] = false;
      check = true;
      --deckCount;
    }
  } while (check && deckCount != 0);
  if (deckCount != 0) std::cout << " - Past!\n" << std::endl;
}

int main() {
  std::cout << "--- Sea battle ---" << std::endl;
  std::array<std::array<bool, fieldSize>, fieldSize> field1{};
  std::array<std::array<bool, fieldSize>, fieldSize> field1Attacking{};
  std::array<std::array<bool, fieldSize>, fieldSize> field2{};
  std::array<std::array<bool, fieldSize>, fieldSize> field2Attacking{};

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
  FieldCreation(field1, player1);
  std::cout << player2 << ", choose places for your ships.\n";
  FieldCreation(field2, player2);

  int deckCountPlayer1 = 20, deckCountPlayer2 = 20;
  bool move{false};
  do {
    if (!move) {
      std::cout << "\n===================" << std::endl << player1 << ", your move." << std::endl;
      Game(field1Attacking, field2, deckCountPlayer2);
    } else {
      std::cout << "\n===================" << std::endl << player2 << ", your move." << std::endl;
      Game(field2Attacking, field1, deckCountPlayer1);
    }
    move = !move;
  } while (deckCountPlayer1 != 0 && deckCountPlayer2 != 0);
  if (deckCountPlayer1 == 0)std::cout << player2 << " won!\n";
  else std::cout << player1 << " won!\n";

  return 0;
}
