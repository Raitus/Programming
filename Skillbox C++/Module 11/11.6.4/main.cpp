#include <iostream>
#include "string"

int CheckProcessing(std::string firstNumber, std::string secondNumber, int j, int k, int i, int shift) {
  if (i==0 && j!=k) {
	if (j > k) {
	  return 1;
	} else {
	  return 2;
	}
  } else {
	for (int l = 0 + shift; (j > k ? l < j : l < k); l++) {
	  if (firstNumber[l] > secondNumber[l]) {
		return 1;
	  } else if (firstNumber[l] < secondNumber[l]) {
		return 2;
	  }
	}
	if (j==firstNumber.length() && k==secondNumber.length()) {
	  return 3;
	} else {
	  if (firstNumber.length()==j) {
		for (int l = k + 1; l < secondNumber.length(); l++) {
		  if (secondNumber[l]!='0') {
			return 2;
		  } else if (l==secondNumber.length() - 1 && secondNumber[l]=='0') {
			return 3;
		  }
		}
	  } else if (secondNumber.length()==k) {
		for (int l = j + 1; l < firstNumber.length(); l++) {
		  if (firstNumber[l]!='0') {
			return 1;
		  } else if (l==firstNumber.length() - 1 && firstNumber[l]=='0') {
			return 3;
		  }
		}
	  }
	}
  }
  return 0;
}

int CheckNumber(std::string firstNumber, std::string secondNumber) {
  for (int i = 0, j = 0, k = 0, shift = 0, finalCheck;
	   (firstNumber.length() > secondNumber.length() ? j + i < firstNumber.length() : k + i < secondNumber.length());
	   i++) {
	for (j += i; j < firstNumber.length() && firstNumber[j]!='.'; j++) {
	}
	for (k += i; k < secondNumber.length() && secondNumber[k]!='.'; k++) {
	}
	if (firstNumber[0]=='-' || secondNumber[0]=='-') {
	  if (firstNumber[i]=='-' && secondNumber[i]!='-') {
		return 1;
	  } else if (firstNumber[i]!='-' && secondNumber[i]=='-') {
		return 2;
	  } else {
		if (i==0)shift += 1;
		finalCheck = CheckProcessing(secondNumber, firstNumber, k, j, i, shift);
		shift+=j;
	  }
	} else {
	  finalCheck = CheckProcessing(firstNumber, secondNumber, j, k, i, shift);
	}
	if (finalCheck!=0) {
	  if (finalCheck==1)return 1;
	  else if (finalCheck==2)return 2;
	  else return 3;
	}
  }
  return 0;
}

bool NumberValidation(std::string number) {
  bool num = false;
  if (number[0]=='-' || (number[0] - '0' >= 0 && number[0] - '0' <= 9) || number[0]=='.') {
	bool dot = false;
	for (int i = 0; i < number.length(); i++) {
	  if (number[i] - '0' >= 0 && number[i] - '0' < 10) num = true;
	  else if (number[0]=='-') {}
	  else if (number[i]=='.' && !dot) dot = true;
	  else {
		return false;
	  }
	}
	if (num) return true;
  } else {
	return false;
  }
  return false;
}

int main() {
  std::string firstNumber, secondNumber;
  std::cout << "Input first number: ";
  std::getline(std::cin, firstNumber);
  std::cout << "and second number: ";
  std::getline(std::cin, secondNumber);
  if (NumberValidation(firstNumber) && NumberValidation(secondNumber)) {
	int check = CheckNumber(firstNumber, secondNumber);
	if (check==1) {
	  std::cout << "More!";
	} else if (check==2) {
	  std::cout << "Less!";
	} else if (check==3) {
	  std::cout << "Equal!";
	} else {
	  std::cout << "Something incorrect!";
	}
  } else {
	std::cout << "Something incorrect!";
  }
  return 0;
}