#include <iostream>
#include <string>

bool StringCheck(std::string &text) {
  for (char i: text) {
    if (!((i >= '/' && i <= '9') || i == '*' || i == '-' || i == '+' || i == '.')) {
      return false;
    }
  }
  return true;
}

void StringInput(std::string &inputField) {
  bool check{false};
  do {
    std::cout << "Input string: ";
    std::cin >> inputField;
    if (StringCheck(inputField)) {
      check = true;
    } else {
      std::cout << "Wrong input! Try again." << std::endl;
    }
  } while (!check);
}

void Calculation(double firstNumber, char arithmeticSign, double secondNumber) {
  std::cout << "Result is ";
  if (arithmeticSign == '+') {
    std::cout << firstNumber + secondNumber;
  } else if (arithmeticSign == '-') {
    std::cout << firstNumber - secondNumber;
  } else if (arithmeticSign == '*') {
    std::cout << firstNumber*secondNumber;
  } else {
    if (secondNumber != 0) {
      std::cout << firstNumber/secondNumber;
    } else {
      std::cout << firstNumber;
    }
  }
}

void StringDefragmentation(std::string &inputField) {
  std::string firstNumber, secondNumber;
  char arithmeticSign;
  bool firstPartCheck{false};
  for (char i : inputField) {
    if (!firstPartCheck) {
      if (!(i == '*' || i == '-' || i == '+' || i == '/')) {
        firstNumber += i;
      } else {
        arithmeticSign = i;
        firstPartCheck = true;
      }
    } else {
      secondNumber += i;
    }
  }
  Calculation(std::stod(firstNumber), arithmeticSign, std::stod(secondNumber));
}

int main() {
  std::cout << "--- M16 Calculator ---" << std::endl;
  std::string inputField;
  StringInput(inputField);
  StringDefragmentation(inputField);
  return 0;
}
