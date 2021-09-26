#include <iostream>
#include <algorithm>
#include <string>

void NumberCheck(std::string &number, int &numberCount, int &index){
  if (!(number[index] >= '0' && number[index] <= '9')) {
    number.erase(number.begin()+index);
    index--;
  } else {
    numberCount++;
  }
}

void FractionalNumberCheck(std::string &number, bool partOfTheNumber) {
  bool dot{false};
  int numberCount{0};
  for (int i = 0; i < number.size(); ++i) {
    if (!partOfTheNumber) {
      if (!dot && number[i] == '.')dot = true;
      else if (dot) {
        NumberCheck(number, numberCount, i);
      }
    } else {
      if (!(i == 0 && number[i] == '-')) {
        NumberCheck(number, numberCount, i);
      }
    }
  }
  if (numberCount == 0) number += '0';
}

int main() {
  std::cout << "--- Fractional Number Sewer ---" << std::endl;
  std::string fractionalNumber;
  std::cout << "Input first part of fractional finalNumber: ";
  std::cin >> fractionalNumber;
  FractionalNumberCheck(fractionalNumber, true);
  fractionalNumber += '.';
  {
    std::string partOfTheNumber;
    std::cin >> partOfTheNumber;
    fractionalNumber+=partOfTheNumber;
  }
  FractionalNumberCheck(fractionalNumber, false);

  double result{std::stod(fractionalNumber)};
  std::cout << "Result: " << result;

  return 0;
}