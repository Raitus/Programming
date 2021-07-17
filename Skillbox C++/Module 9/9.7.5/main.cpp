#include <iostream>

int main() {
  std::string number;
  std::cout << "Input number: ";
  std::cin >> number;

  if (number.length() > 4 || (number.length()==4
	  && (number[0] < '0' || number[0] > '9' || number[1] < '0' || number[1] > '9' || number[2] < '0'
		  || number[2] > '9' || number[3] < '0' || number[3] > '9')) || (number.length()==3
	  && (number[0] < '0' || number[0] > '9' || number[1] < '0' || number[1] > '9' || number[2] < '0'
		  || number[2] > '9'))
	  || (number.length()==2 && (number[0] < '0' || number[0] > '9' || number[1] < '0' || number[1] > '9'))
	  || (number.length()==1 && (number[0] < '0' || number[0] > '9'))
	  || (number.length()==4
		  && ((number[0] - '0')*1000 + (number[1] - '0')*100 + (number[2] - '0')*10 + (number[3] - '0')) > 3999)) {
	std::cout << "Wrong number! Input between 1 and 3999.\n";
  } else {
	int stringSize = number.length(), numberOfSymbol = 0;
	if (stringSize==4 && number[numberOfSymbol] - '0' > 0) { //thousands
	  for (int i = 0; number[numberOfSymbol] - '0' > 0 && i < 3; i++) {
		number[numberOfSymbol] -= 1;
		std::cout << 'M';
	  }
	  stringSize--;
	  numberOfSymbol++;
	}
	if (stringSize==3 && number[numberOfSymbol] - '0' > 0) { //hundreds
	  if (number[numberOfSymbol] - '0'==9) {
		number[numberOfSymbol] -= 9;
		std::cout << "CM";
	  } else if (number[numberOfSymbol] - '0' >= 5) {
		std::cout << "D";
		number[numberOfSymbol] -= 5;
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'C';
		}
	  } else if (number[numberOfSymbol] - '0'==4) {
		std::cout << "CD";
	  } else {
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'C';
		}
	  }
	  stringSize--;
	  numberOfSymbol++;
	}
	if (stringSize==2 && number[numberOfSymbol] - '0' > 0) { //decimal
	  if (number[numberOfSymbol] - '0'==9) {
		number[numberOfSymbol] -= 9;
		std::cout << "XC";
	  } else if (number[numberOfSymbol] - '0' >= 5) {
		std::cout << "L";
		number[numberOfSymbol] -= 5;
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'X';
		}
	  } else if (number[numberOfSymbol] - '0'==4) {
		std::cout << "XL";
	  } else {
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'X';
		}
	  }
	  stringSize--;
	  numberOfSymbol++;
	}
	if (stringSize==1 && number[numberOfSymbol] - '0' > 0) { //units
	  if (number[numberOfSymbol] - '0'==9) {
		number[numberOfSymbol] -= 9;
		std::cout << "IX";
	  } else if (number[numberOfSymbol] - '0' >= 5) {
		std::cout << "V";
		number[numberOfSymbol] -= 5;
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'I';
		}
	  } else if (number[numberOfSymbol] - '0'==4) {
		std::cout << "IV";
	  } else {
		for (int i = 0; number[numberOfSymbol] - '0' > 0; i++) {
		  number[numberOfSymbol] -= 1;
		  std::cout << 'I';
		}
	  }
	}
  }
  return 0;
}
