#include <iostream>
#include <string>
#include <sstream>

bool StringCheckAndTransform(std::string &text) {
  for (int i{0}, lengthMinus{0};i<text.size()-lengthMinus;++i) {
    if (!((text[i] >= '/' && text[i] <= '9') || text[i] == '*' || text[i] == '-' || text[i] == '+' || text[i] == '.')) {
      return false;
    }
    if (text[i]=='*'||text[i]=='/'||text[i]=='-'||text[i]=='+'){
      char sign{text[i]};
      text[i]=' ';
      text+=' ';
      text+=sign;
      lengthMinus=2;
    }
  }
  return true;
}

void StringInput(std::stringstream &inputField) {
  do {
    std::string inputString;
    std::cout << "Input string: ";
    std::cin >> inputString;
    if (StringCheckAndTransform(inputString)) {
      inputField<<inputString;
      break;
    } else {
      std::cout << "Wrong input! Try again." << std::endl;
    }
  } while (true);
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

void StringDefragmentation(std::stringstream &inputField) {
  std::string firstNumber, secondNumber;
  char arithmeticSign;
  inputField>>firstNumber>>secondNumber>>arithmeticSign;
  Calculation(std::stod(firstNumber), arithmeticSign, std::stod(secondNumber));
}

int main() {
  std::cout << "--- M16 Calculator ---" << std::endl;
  std::stringstream inputField;
  StringInput(inputField);
  StringDefragmentation(inputField);
  return 0;
}
