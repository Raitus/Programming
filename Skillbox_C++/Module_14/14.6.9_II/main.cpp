#include <iostream>
#include "array"
#include "vector"
#include "random"
#include "ctime"

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

bool CoordinatesChecking(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                         int x1,
                         int y1,
                         int x2,
                         int y2) {
  if (x1 == x2) {
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

void BotShipArrangement(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                        std::vector<int> &xCoordinates,
                        std::vector<int> &yCoordinates,
                        int shipSize,
                        std::mt19937 &gen,
                        std::uniform_int_distribution<> &width) {

  std::uniform_int_distribution<> circleDegree(0, 359);
  int x1, y1, x2{-1}, y2{-1}, degree;
  bool bordersMistake, top, left, bottom, right;
  //input coordinates
  do {
    top = false, left = false, bottom = false, right = false;
    x1 = width(gen);
    y1 = width(gen);
    degree = circleDegree(gen);
    do {
      bordersMistake = false;
      if (!top && degree > 45 && degree <= 135) { //top
        top = true;
        x2 = x1;
        if (y1 - (shipSize - 1) >= 0)y2 = y1 - (shipSize - 1);
      } else if (!left && degree > 135 && degree <= 225) { //left
        left = true;
        if (x1 - (shipSize - 1) >= 0) x2 = x1 - (shipSize - 1);
        y2 = y1;
      } else if (!bottom && degree > 225 && degree <= 315) { //bottom
        bottom = true;
        x2 = x1;
        if (y1 + (shipSize - 1) <= 9)y2 = y1 + (shipSize - 1);
      } else if (!right) { //right
        right = true;
        if (x1 + (shipSize - 1) <= 9) x2 = x1 + (shipSize - 1);
        y2 = y1;
      }
      if (x2 == -1 || y2 == -1 || !BorderChecking(field, x1, y1, x2, y2)) {
        bordersMistake = true;
        degree = (degree + 90)%360;
        if (top && left && bottom && right) break;
      }
    } while (bordersMistake);
  } while (bordersMistake);

  xCoordinates.push_back(x1);
  xCoordinates.push_back(x2);
  yCoordinates.push_back(y1);
  yCoordinates.push_back(y2);
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

void ShipArrangement(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                     std::vector<int> &xCoordinates,
                     std::vector<int> &yCoordinates,
                     int shipSize) {
  int x1, y1, x2, y2;
  bool correctness;
  std::cout << "Input coordinates: ";
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
  xCoordinates.push_back(x1);
  xCoordinates.push_back(x2);
  yCoordinates.push_back(y1);
  yCoordinates.push_back(y2);
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

void BotFieldCreation(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                      std::vector<int> &xCoordinates,
                      std::vector<int> &yCoordinates) {
  //std::random_device rd; //random_device is not working in our case. I found that ships arrangement each time, on the same places.
  std::mt19937 gen(time(nullptr));
  std::uniform_int_distribution<> width(0, 9);
  BotShipArrangement(field, xCoordinates, yCoordinates, 4, gen, width);
  for (int i = 0; i < 2; ++i) {
    BotShipArrangement(field, xCoordinates, yCoordinates, 3, gen, width);
  }
  for (int i = 0; i < 3; ++i) {
    BotShipArrangement(field, xCoordinates, yCoordinates, 2, gen, width);
  }
  for (int i = 0; i < 4; ++i) {
    int x, y;
    bool bordersMistake;
    //input coordinates
    do {
      bordersMistake = false;
      x = width(gen);
      y = width(gen);
      if (!BorderChecking(field, x, y, x, y)) {
        bordersMistake = true;
      }
    } while (bordersMistake);

    xCoordinates.push_back(x);
    xCoordinates.push_back(x);
    yCoordinates.push_back(y);
    yCoordinates.push_back(y);
    field[y][x] = true;
  }
}

void FieldCreation(std::array<std::array<bool, fieldSize>, fieldSize> &field,
                   std::vector<int> &xCoordinates,
                   std::vector<int> &yCoordinates) {
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
        std::cout << "Choose the size of the ship, which do you want to place on the board (from 1 to 4): ";
        std::cin >> shipSize;
      } while (shipSize < 1 || shipSize > 4);
      if (shipSize == 1 && ship1 != 0) {
        ship1--;
        int x, y;
        bool bordersMistake;
        std::cout << "Input coordinates: ";
        do {
          bordersMistake = false;
          CoordinatesInput(x, y);
          if (!BorderChecking(field, x, y, x, y)) {
            bordersMistake = true;
          }
        } while (bordersMistake);

        xCoordinates.push_back(x);
        xCoordinates.push_back(x);
        yCoordinates.push_back(y);
        yCoordinates.push_back(y);
        field[y][x] = true;

      } else if (shipSize == 2 && ship2 != 0) {
        ship2--;
        ShipArrangement(field, xCoordinates, yCoordinates, shipSize);
      } else if (shipSize == 3 && ship3 != 0) {
        ship3--;
        ShipArrangement(field, xCoordinates, yCoordinates, shipSize);
      } else if (shipSize == 4 && ship4) {
        ship4 = false;
        ShipArrangement(field, xCoordinates, yCoordinates, shipSize);
      } else {
        check = true;
        std::cout << "All ships with this size on the board.\n";
      }
    } while (check);

  }
}

bool ShipDefeatingCheck(std::array<std::array<bool, fieldSize>, fieldSize> &opponentField,
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
      std::cout << " - Defeated ship!" << std::endl;
      return true;
    }
  }
  return false;
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
      CoordinatesInput(x, y);
      if (attackingField[y][x])std::cout << "Wrong coordinates of attack. Try again!\n";
    } while (attackingField[y][x]);
    attackingField[y][x] = true;
    if (attackingField[y][x] == opponentField[y][x]) {
      std::cout << " - Hit!" << std::endl;
      opponentField[y][x] = false;
      check = true;
      ShipDefeatingCheck(opponentField, xCoordinates, yCoordinates, shipCount);
    }
  } while (check && shipCount != 0);
  if (shipCount != 0) std::cout << " - Past!" << std::endl;
}

void BotMove(std::array<std::array<bool, fieldSize>, fieldSize> &attackingField,
             std::array<std::array<bool, fieldSize>, fieldSize> &opponentField,
             std::vector<int> &xCoordinates,
             std::vector<int> &yCoordinates,
             int &shipCount,
             std::string &player1,
             std::array<std::array<bool, fieldSize>, fieldSize> &player1AttackingField,
             std::array<std::array<bool, fieldSize>, fieldSize> &player1opponentField,
             std::vector<int> &player1xCoordinates,
             std::vector<int> &player1yCoordinates,
             int &player2ShipCount) {
  int x, y;
  bool check;
  do {
    check = false;
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> width(0, 9), circleDegree(0, 359);
    do {
      x = width(gen);
      y = width(gen);
      //CoordinatesInput(x, y);
    } while (attackingField[y][x]);
    attackingField[y][x] = true;
    if (opponentField[y][x]) {
      std::cout << " - Hit!" << std::endl;
      opponentField[y][x] = false;
      check = true;
      if (!ShipDefeatingCheck(opponentField, xCoordinates, yCoordinates, shipCount)) {
        int degree = circleDegree(gen);
        bool border;
        do {
          int xt = x, yt = y;
          bool direction, player1Move{false};
          border = false;
          //bool top = false, left = false, bottom = false, right = false;
          //input coordinates
          do {
            direction = true;
            if (degree > 45 && degree <= 135) { //top
              if (yt > 0) {
                --yt;
              } else {
                if (std::abs(yt - y) == 0) { //достигнута граница, идём влево
                  degree = (degree + 90)%360;
                  border = true;
                  break;
                } else { //достигнута граница, идём в другую сторону
                  degree = (degree + 180)%360;
                  border = true;
                  break;
                }
              }
            } else if (degree > 135 && degree <= 225) { //left
              if (xt > 0) {
                --xt;
              } else {
                if (std::abs(xt - x) == 0) { //достигнута граница, идём влево
                  degree = (degree + 90)%360;
                  border = true;
                  break;
                } else { //достигнута граница, идём в другую сторону
                  degree = (degree + 180)%360;
                  border = true;
                  break;
                }
              }
            } else if (degree > 225 && degree <= 315) { //bottom
              if (yt < 9) {
                ++yt;
              } else {
                if (std::abs(yt - y) == 0) { //достигнута граница, идём влево
                  degree = (degree + 90)%360;
                  border = true;
                  break;
                } else { //достигнута граница, идём в другую сторону
                  degree = (degree + 180)%360;
                  border = true;
                  break;
                }
              }
            } else { //right
              if (xt < 9) {
                ++xt;
              } else {
                if (std::abs(xt - x) == 0) { //достигнута граница, идём влево
                  degree = (degree + 90)%360;
                  border = true;
                  break;
                } else { //достигнута граница, идём в другую сторону
                  degree = (degree + 180)%360;
                  border = true;
                  break;
                }
              }
            }

            if (attackingField[yt][xt]) { //стреляли ли мы сюда?
              yt = y;
              xt = x;
              degree = (degree + 90)%360;
              direction = false;
            } else {
              attackingField[yt][xt] = true;
              if (!opponentField[yt][xt]) { //Если не попали
                std::cout << " - Past!" << std::endl;
                if (std::abs(xt - x) == 1 || std::abs(yt - y) == 1) {
                  degree = (degree + 90)%360;
                } else if (std::abs(xt - x) > 1 || std::abs(yt - y) > 1) {
                  degree = (degree + 180)%360;
                }
                yt = y;
                xt = x;
                Visualisation(attackingField);
                player1Move = true;
                std::cout << "\n===================" << std::endl << player1 << ", your move." << std::endl;
                Game(player1AttackingField,
                     player1opponentField,
                     player1xCoordinates,
                     player1yCoordinates,
                     player2ShipCount);
                if (player2ShipCount == 0)break;
              } else {
                opponentField[yt][xt] = false;
                std::cout << " - Hit!" << std::endl;
                player1Move = false;
                Visualisation(attackingField);
              }
            }

          } while (player1Move || !direction
              || !ShipDefeatingCheck(opponentField,
                                     xCoordinates,
                                     yCoordinates,
                                     shipCount)); //пока хоть одно условие не выполняется
        } while (border);
      }
    }else{
      std::cout << " - Past!" << std::endl;
    }
  } while (check && shipCount != 0);
  Visualisation(attackingField);
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

  char answer;
  {
    bool check;
    std::cout << "Do you want to play with artificial intelligence? (Y/N) ";
    do {
      check = false;
      std::cin >> answer;
      if (answer != 'Y' && answer != 'N') {
        check = true;
        std::cout << "Incorrect answer! Choose between Y & N. ";
      }
    } while (check);
  }
  int shipCountPlayer1 = 10, shipCountPlayer2 = 10;
  if (answer == 'Y') {
    std::cout << player1 << ", choose places for your ships.\n";
    FieldCreation(field1, xCoordinatesField1, yCoordinatesField1);
    std::cout << player2 << " is creating his field.\n";
    BotFieldCreation(field2, xCoordinatesField2, yCoordinatesField2);
    //Visualisation(field2);
    {
      bool move{false};
      do {
        if (!move) {
          std::cout << "\n===================" << std::endl << player1 << ", your move." << std::endl;
          Game(field1Attacking, field2, xCoordinatesField2, yCoordinatesField2, shipCountPlayer2);
        } else {
          std::cout << "\n===================" << std::endl << player2 << " is moving." << std::endl;
          BotMove(field2Attacking, field1, xCoordinatesField1, yCoordinatesField1, shipCountPlayer1, player1,
                  field1Attacking, field2, xCoordinatesField2, yCoordinatesField2, shipCountPlayer2);
          //Game(field2Attacking, field1, deckCountPlayer1);
        }
        move = !move;
      } while (shipCountPlayer1 != 0 && shipCountPlayer2 != 0);
    }
  } else {
    std::cout << player1 << ", choose places for your ships.\n";
    FieldCreation(field1, xCoordinatesField1, yCoordinatesField1);
    std::cout << player2 << ", choose places for your ships.\n";
    FieldCreation(field2, xCoordinatesField2, yCoordinatesField2);
    {
      bool move{false};
      do {
        if (!move) {
          std::cout << "\n===================" << std::endl << player1 << ", your move." << std::endl;
          Game(field1Attacking, field2, xCoordinatesField2, yCoordinatesField2, shipCountPlayer2);
        } else {
          std::cout << "\n===================" << std::endl << player2 << ", your move." << std::endl;
          Game(field2Attacking, field1, xCoordinatesField1, yCoordinatesField1, shipCountPlayer1);
        }
        move = !move;
      } while (shipCountPlayer1 != 0 && shipCountPlayer2 != 0);
    }
  }

  if (shipCountPlayer1 == 0)std::cout << player2 << " won!\n";
  else std::cout << player1 << " won!\n";

  return 0;
}
