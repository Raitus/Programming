#include <iostream>

int main() {
  std::cout << "--- Human ant hill ---\n" << std::endl;
  std::string array[10];
  int length = sizeof(array)/sizeof(array[0]);
  for (int i = 0; i < length; ++i) {
	std::cin>>array[i];
  }
  std::cout<<"Choose apartment number:\n";
  for (int i = 0, flatNumber; i < 3; ++i) {
    do{
	  std::cin>>flatNumber;
	  if (flatNumber<0||flatNumber>length){
		std::cout<<"Incorrect apartment number! Try again.\n";
	  }
    }while(flatNumber<=0||flatNumber>length);

	std::cout<<array[flatNumber-1]<<std::endl;
  }
  return 0;
}
