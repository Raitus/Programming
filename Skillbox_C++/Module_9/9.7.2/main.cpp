#include <iostream>

int main() {
  std::string firstNumber, secondNumber;
  std::cout << "Input conceived number: ";
  std::cin >> firstNumber;
  std::cout << "Input second number: ";
  std::cin >> secondNumber;

  if (firstNumber.length()==4 && secondNumber.length()==4 && firstNumber[0] >= '0' && firstNumber[0] <= '9'
	  && firstNumber[1] >= '0' && firstNumber[1] <= '9' && firstNumber[2] >= '0'
	  && firstNumber[2] <= '9' && firstNumber[3] >= '0' && firstNumber[3] <= '9'
	  && secondNumber[0] >= '0' && secondNumber[0] <= '9' && secondNumber[1] >= '0'
	  && secondNumber[1] <= '9' && secondNumber[2] >= '0' && secondNumber[2] <= '9'
	  && secondNumber[3] >= '0' && secondNumber[3] <= '9') {
	int cow = 0, bull = 0;
	for (int i = 0; i < firstNumber.length(); i++) {
	  if (firstNumber[i]==secondNumber[i]) {
		bull++;
	  }else if (i==0 || (i==1 && firstNumber[i]!=firstNumber[0])
		  || (i==2 && firstNumber[i]!=firstNumber[0] && firstNumber[i]!=firstNumber[1])
		  || (i==3 && firstNumber[i]!=firstNumber[0] && firstNumber[i]!=firstNumber[1]
			  && firstNumber[i]!=firstNumber[2])) {
		for (int y = 0; y < secondNumber.length(); y++) {
		  if (firstNumber[i]==secondNumber[y] && firstNumber[i]!=secondNumber[i] && secondNumber[y]!=firstNumber[y]) {
			cow++;
			break;
		  }
		}
	  }
	}
	std::cout << "Bulls: " << bull << ", cows: " << cow << ".\n";
  } else {
	std::cout << "Error! Please, input number in the right format.\n";
  }
  return 0;
}
